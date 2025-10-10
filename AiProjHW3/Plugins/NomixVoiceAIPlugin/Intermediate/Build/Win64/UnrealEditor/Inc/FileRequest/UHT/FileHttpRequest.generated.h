// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FileHttpRequest.h"

#ifdef FILEREQUEST_FileHttpRequest_generated_h
#error "FileHttpRequest.generated.h already included, missing '#pragma once' in FileHttpRequest.h"
#endif
#define FILEREQUEST_FileHttpRequest_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UFileHttpRequest;
class UObject;

// ********** Begin Delegate FOnRequestComplete ****************************************************
#define FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_9_DELEGATE \
FILEREQUEST_API void FOnRequestComplete_DelegateWrapper(const FMulticastScriptDelegate& OnRequestComplete, const FString& Response);


// ********** End Delegate FOnRequestComplete ******************************************************

// ********** Begin Class UFileHttpRequest *********************************************************
#define FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncASRSendRequest);


FILEREQUEST_API UClass* Z_Construct_UClass_UFileHttpRequest_NoRegister();

#define FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFileHttpRequest(); \
	friend struct Z_Construct_UClass_UFileHttpRequest_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend FILEREQUEST_API UClass* Z_Construct_UClass_UFileHttpRequest_NoRegister(); \
public: \
	DECLARE_CLASS2(UFileHttpRequest, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FileRequest"), Z_Construct_UClass_UFileHttpRequest_NoRegister) \
	DECLARE_SERIALIZER(UFileHttpRequest)


#define FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFileHttpRequest(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UFileHttpRequest(UFileHttpRequest&&) = delete; \
	UFileHttpRequest(const UFileHttpRequest&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFileHttpRequest); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFileHttpRequest); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFileHttpRequest) \
	NO_API virtual ~UFileHttpRequest();


#define FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_11_PROLOG
#define FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UFileHttpRequest;

// ********** End Class UFileHttpRequest ***********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
