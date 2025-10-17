#include "FileHttpRequest.h"
#include "HttpModule.h"
#include "Engine/Engine.h"
#include "Interfaces/IHttpResponse.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "Sound/SoundWave.h"

TArray<uint8> FStringToUint8(const FString& InString)
{
	TArray<uint8> OutBytes;

	// Handle empty strings
	if (InString.Len() > 0)
	{
		FTCHARToUTF8 Converted(*InString); // Convert to UTF8
		OutBytes.Append(reinterpret_cast<const uint8*>(Converted.Get()), Converted.Length());
	}

	return OutBytes;
}

void UFileHttpRequest::Activate()
{
	// Create a boundary label, for the header
	const FString BoundaryLabel = FString(TEXT("e543322540af456f9a3773049ca02529-")) + FString::FromInt(FMath::Rand());
	// boundary label for beginning of every payload chunk 
	const FString BoundaryBegin = FString(TEXT("--")) + BoundaryLabel + FString(TEXT("\r\n"));
	// boundary label for the end of payload
	const FString BoundaryEnd = FString(TEXT("\r\n--")) + BoundaryLabel + FString(TEXT("--\r\n"));
	
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UFileHttpRequest::OnResponseReceived);

	// This is binary content of the request
	TArray<uint8> CombinedContent;
	
	// Convert relative path to absolute if needed
	FString AbsoluteFilePath = FilePath;
	if (FPaths::IsRelative(FilePath))
	{
		AbsoluteFilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir(), FilePath);
	}
	
	// Load File
	TArray<uint8> FileData;
	if (!FFileHelper::LoadFileToArray(FileData, *AbsoluteFilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *AbsoluteFilePath);
		OnRequestComplete.Broadcast("{\"error\":\"Failed to load file\"}");
		return;
	}
	
	UE_LOG(LogTemp, Log, TEXT("File loaded successfully: %s, Size: %d bytes"), *AbsoluteFilePath, FileData.Num());

	// Generate a boundary for the file field
	const FString FileBoundaryString = FString(TEXT("\r\n"))
		+ BoundaryBegin
		+ FString(TEXT("Content-Disposition: form-data; name=\"file\"; filename=\""))
		+ FPaths::GetCleanFilename(AbsoluteFilePath) + "\"\r\n"
		+ "Content-Type: audio/wav"
		+ FString(TEXT("\r\n\r\n"));
	
	CombinedContent.Append(FStringToUint8(FileBoundaryString));
	CombinedContent.Append(FileData);
	
	// Add model field to the form
	const FString ModelBoundaryString = FString(TEXT("\r\n"))
		+ BoundaryBegin
		+ FString(TEXT("Content-Disposition: form-data; name=\"model\"\r\n\r\n"))
		+ Model;
	
	CombinedContent.Append(FStringToUint8(ModelBoundaryString));
	CombinedContent.Append(FStringToUint8(BoundaryEnd));
	
	Request->SetURL(URL);
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "multipart/form-data; boundary=" + BoundaryLabel);
	Request->SetHeader("Authorization", ApiKey);
	Request->SetHeader("accept", "application/json");
	Request->SetContent(CombinedContent);
	
	Request->ProcessRequest();
}

UFileHttpRequest* UFileHttpRequest::AsyncASRSendRequest(UObject* WorldContextObject, FString URL, FString ApiKey, FString Model, FString FilePath)
{
	UFileHttpRequest* Action = NewObject<UFileHttpRequest>();
	Action->URL = URL;
	Action->ApiKey = ApiKey;
	Action->Model = Model;
	Action->FilePath = FilePath;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}


void UFileHttpRequest::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response.IsValid())
	{
		OnRequestComplete.Broadcast(Response->GetContentAsString());
	}
	else
	{
		OnRequestComplete.Broadcast("");	
	}
}

// TTS Implementation
UTTSHttpRequest* UTTSHttpRequest::AsyncTTSSendRequest(UObject* WorldContextObject, FString URL, FString ApiKey, FString Model, FString Voice, FString Input, FString Instructions)
{
	UTTSHttpRequest* Action = NewObject<UTTSHttpRequest>();
	Action->URL = URL;
	Action->ApiKey = ApiKey;
	Action->Model = Model;
	Action->Voice = Voice;
	Action->Input = Input;
	Action->Instructions = Instructions;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}

void UTTSHttpRequest::Activate()
{
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UTTSHttpRequest::OnTTSResponseReceived);

	// Create JSON payload
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("model", Model);
	JsonObject->SetStringField("input", Input);
	JsonObject->SetStringField("voice", Voice);
	JsonObject->SetStringField("response_format", "wav"); // Request WAV format instead of MP3
	
	if (!Instructions.IsEmpty())
	{
		JsonObject->SetStringField("instructions", Instructions);
	}

	// Serialize JSON to string
	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	Request->SetURL(URL);
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetHeader("Authorization", ApiKey);
	Request->SetContentAsString(OutputString);
	
	UE_LOG(LogTemp, Log, TEXT("TTS Request sent to: %s"), *URL);
	Request->ProcessRequest();
}

void UTTSHttpRequest::OnTTSResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response.IsValid() && Response->GetResponseCode() == 200)
	{
		const TArray<uint8>& AudioData = Response->GetContent();
		
		if (AudioData.Num() > 0)
		{
			USoundWave* SoundWave = CreateSoundWaveFromWAVData(AudioData);
			if (SoundWave)
			{
				UE_LOG(LogTemp, Log, TEXT("TTS SoundWave created successfully"));
				OnTTSRequestComplete.Broadcast(SoundWave, true);
				return;
			}
		}
	}
	
	UE_LOG(LogTemp, Error, TEXT("TTS Request failed"));
	OnTTSRequestComplete.Broadcast(nullptr, false);
}

USoundWave* UTTSHttpRequest::CreateSoundWaveFromWAVData(const TArray<uint8>& WAVData)
{
	USoundWave* SoundWave = NewObject<USoundWave>();
	if (!SoundWave)
	{
		return nullptr;
	}

	// Store the WAV data using the new API
	SoundWave->RawData.UpdatePayload(FSharedBuffer::Clone(WAVData.GetData(), WAVData.Num()));

	// Set basic properties for WAV using public methods
	// Don't set Duration - let the engine calculate it from WAV data
	SoundWave->NumChannels = 2; // Will be read from WAV header
	SoundWave->SetSampleRate(44100); // Will be read from WAV header
	
	// Ensure it's not looping
	SoundWave->bLooping = false;
	
	// Invalidate compressed data to force reprocessing
	SoundWave->InvalidateCompressedData();
	
	UE_LOG(LogTemp, Log, TEXT("WAV SoundWave created with %d bytes"), WAVData.Num());
	
	return SoundWave;
}