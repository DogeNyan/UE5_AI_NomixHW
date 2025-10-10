#include "FileHttpRequest.h"
#include "HttpModule.h"
#include "Engine/Engine.h"
#include "Interfaces/IHttpResponse.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

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