// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FileHttpRequest.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeFileHttpRequest() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
FILEREQUEST_API UClass* Z_Construct_UClass_UFileHttpRequest();
FILEREQUEST_API UClass* Z_Construct_UClass_UFileHttpRequest_NoRegister();
FILEREQUEST_API UFunction* Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_FileRequest();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnRequestComplete ****************************************************
struct Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics
{
	struct _Script_FileRequest_eventOnRequestComplete_Parms
	{
		FString Response;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FileHttpRequest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Response_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Response;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::NewProp_Response = { "Response", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_FileRequest_eventOnRequestComplete_Parms, Response), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Response_MetaData), NewProp_Response_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::NewProp_Response,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_FileRequest, nullptr, "OnRequestComplete__DelegateSignature", Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::_Script_FileRequest_eventOnRequestComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::_Script_FileRequest_eventOnRequestComplete_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnRequestComplete_DelegateWrapper(const FMulticastScriptDelegate& OnRequestComplete, const FString& Response)
{
	struct _Script_FileRequest_eventOnRequestComplete_Parms
	{
		FString Response;
	};
	_Script_FileRequest_eventOnRequestComplete_Parms Parms;
	Parms.Response=Response;
	OnRequestComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnRequestComplete ******************************************************

// ********** Begin Class UFileHttpRequest Function AsyncASRSendRequest ****************************
struct Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics
{
	struct FileHttpRequest_eventAsyncASRSendRequest_Parms
	{
		UObject* WorldContextObject;
		FString URL;
		FString ApiKey;
		FString Model;
		FString FilePath;
		UFileHttpRequest* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Nomix ASR" },
		{ "ModuleRelativePath", "Public/FileHttpRequest.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStrPropertyParams NewProp_URL;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ApiKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Model;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileHttpRequest_eventAsyncASRSendRequest_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_URL = { "URL", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileHttpRequest_eventAsyncASRSendRequest_Parms, URL), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_ApiKey = { "ApiKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileHttpRequest_eventAsyncASRSendRequest_Parms, ApiKey), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_Model = { "Model", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileHttpRequest_eventAsyncASRSendRequest_Parms, Model), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileHttpRequest_eventAsyncASRSendRequest_Parms, FilePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FileHttpRequest_eventAsyncASRSendRequest_Parms, ReturnValue), Z_Construct_UClass_UFileHttpRequest_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_URL,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_ApiKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_Model,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_FilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UFileHttpRequest, nullptr, "AsyncASRSendRequest", Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::FileHttpRequest_eventAsyncASRSendRequest_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::FileHttpRequest_eventAsyncASRSendRequest_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UFileHttpRequest::execAsyncASRSendRequest)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_PROPERTY(FStrProperty,Z_Param_URL);
	P_GET_PROPERTY(FStrProperty,Z_Param_ApiKey);
	P_GET_PROPERTY(FStrProperty,Z_Param_Model);
	P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UFileHttpRequest**)Z_Param__Result=UFileHttpRequest::AsyncASRSendRequest(Z_Param_WorldContextObject,Z_Param_URL,Z_Param_ApiKey,Z_Param_Model,Z_Param_FilePath);
	P_NATIVE_END;
}
// ********** End Class UFileHttpRequest Function AsyncASRSendRequest ******************************

// ********** Begin Class UFileHttpRequest *********************************************************
void UFileHttpRequest::StaticRegisterNativesUFileHttpRequest()
{
	UClass* Class = UFileHttpRequest::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AsyncASRSendRequest", &UFileHttpRequest::execAsyncASRSendRequest },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UFileHttpRequest;
UClass* UFileHttpRequest::GetPrivateStaticClass()
{
	using TClass = UFileHttpRequest;
	if (!Z_Registration_Info_UClass_UFileHttpRequest.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("FileHttpRequest"),
			Z_Registration_Info_UClass_UFileHttpRequest.InnerSingleton,
			StaticRegisterNativesUFileHttpRequest,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UFileHttpRequest.InnerSingleton;
}
UClass* Z_Construct_UClass_UFileHttpRequest_NoRegister()
{
	return UFileHttpRequest::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UFileHttpRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FileHttpRequest.h" },
		{ "ModuleRelativePath", "Public/FileHttpRequest.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnRequestComplete_MetaData[] = {
		{ "ModuleRelativePath", "Public/FileHttpRequest.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRequestComplete;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UFileHttpRequest_AsyncASRSendRequest, "AsyncASRSendRequest" }, // 1176816454
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFileHttpRequest>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UFileHttpRequest_Statics::NewProp_OnRequestComplete = { "OnRequestComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UFileHttpRequest, OnRequestComplete), Z_Construct_UDelegateFunction_FileRequest_OnRequestComplete__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnRequestComplete_MetaData), NewProp_OnRequestComplete_MetaData) }; // 615414699
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFileHttpRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFileHttpRequest_Statics::NewProp_OnRequestComplete,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFileHttpRequest_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UFileHttpRequest_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_FileRequest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFileHttpRequest_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UFileHttpRequest_Statics::ClassParams = {
	&UFileHttpRequest::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UFileHttpRequest_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UFileHttpRequest_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFileHttpRequest_Statics::Class_MetaDataParams), Z_Construct_UClass_UFileHttpRequest_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UFileHttpRequest()
{
	if (!Z_Registration_Info_UClass_UFileHttpRequest.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFileHttpRequest.OuterSingleton, Z_Construct_UClass_UFileHttpRequest_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UFileHttpRequest.OuterSingleton;
}
UFileHttpRequest::UFileHttpRequest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UFileHttpRequest);
UFileHttpRequest::~UFileHttpRequest() {}
// ********** End Class UFileHttpRequest ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h__Script_FileRequest_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UFileHttpRequest, UFileHttpRequest::StaticClass, TEXT("UFileHttpRequest"), &Z_Registration_Info_UClass_UFileHttpRequest, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFileHttpRequest), 177935932U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h__Script_FileRequest_564581845(TEXT("/Script/FileRequest"),
	Z_CompiledInDeferFile_FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h__Script_FileRequest_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_vanek_Documents_Unreal_Projects_ai_project_Plugins_NomixVoiceAIPlugin_Source_FileRequest_Public_FileHttpRequest_h__Script_FileRequest_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
