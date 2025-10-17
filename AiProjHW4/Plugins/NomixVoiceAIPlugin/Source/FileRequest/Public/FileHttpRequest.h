#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Sound/SoundWave.h"
#include "FileHttpRequest.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestComplete, const FString&, Response);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTTSRequestComplete, USoundWave*, SoundWave, bool, Success);

UCLASS()
class FILEREQUEST_API UFileHttpRequest : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	virtual void Activate() override;
	
	UPROPERTY(BlueprintAssignable)
	FOnRequestComplete OnRequestComplete;
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nomix ASR", WorldContext = "WorldContextObject"))
	static UFileHttpRequest* AsyncASRSendRequest(UObject* WorldContextObject, FString URL, FString ApiKey, FString Model, FString FilePath);

	FString URL;
	FString ApiKey;
	FString Model;
	FString FilePath;

private:
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};

UCLASS()
class FILEREQUEST_API UTTSHttpRequest : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	virtual void Activate() override;
	
	UPROPERTY(BlueprintAssignable)
	FOnTTSRequestComplete OnTTSRequestComplete;
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Nomix TTS", WorldContext = "WorldContextObject"))
	static UTTSHttpRequest* AsyncTTSSendRequest(UObject* WorldContextObject, FString URL, FString ApiKey, FString Model, FString Voice, FString Input, FString Instructions);

	FString URL;
	FString ApiKey;
	FString Model;
	FString Voice;
	FString Input;
	FString Instructions;

private:
	void OnTTSResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	USoundWave* CreateSoundWaveFromWAVData(const TArray<uint8>& WAVData);
};