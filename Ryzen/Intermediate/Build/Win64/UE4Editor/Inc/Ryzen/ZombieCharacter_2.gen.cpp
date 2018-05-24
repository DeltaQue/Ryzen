// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Zombie/ZombieCharacter_2.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZombieCharacter_2() {}
// Cross Module References
	RYZEN_API UClass* Z_Construct_UClass_AZombieCharacter_2_NoRegister();
	RYZEN_API UClass* Z_Construct_UClass_AZombieCharacter_2();
	RYZEN_API UClass* Z_Construct_UClass_ARyzenBaseCharacter();
	UPackage* Z_Construct_UPackage__Script_Ryzen();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_GetAttackAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_GetAttackAnimMontage();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnAttackCollisionCompBeginOverlap();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnAttackCollisionCompEndOverlap();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnHearNoise();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnSeePlayer();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_PlayAttackMotion();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_ReTriggerAttack();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_ScratchAttack();
	RYZEN_API UFunction* Z_Construct_UFunction_AZombieCharacter_2_TimerHandleFunc();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundCue_NoRegister();
	RYZEN_API UEnum* Z_Construct_UEnum_Ryzen_EZombieType();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UPawnSensingComponent_NoRegister();
// End Cross Module References
	void AZombieCharacter_2::StaticRegisterNativesAZombieCharacter_2()
	{
		UClass* Class = AZombieCharacter_2::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAttackAnimInstance", &AZombieCharacter_2::execGetAttackAnimInstance },
			{ "GetAttackAnimMontage", &AZombieCharacter_2::execGetAttackAnimMontage },
			{ "OnAttackCollisionCompBeginOverlap", &AZombieCharacter_2::execOnAttackCollisionCompBeginOverlap },
			{ "OnAttackCollisionCompEndOverlap", &AZombieCharacter_2::execOnAttackCollisionCompEndOverlap },
			{ "OnHearNoise", &AZombieCharacter_2::execOnHearNoise },
			{ "OnSeePlayer", &AZombieCharacter_2::execOnSeePlayer },
			{ "PlayAttackMotion", &AZombieCharacter_2::execPlayAttackMotion },
			{ "ReTriggerAttack", &AZombieCharacter_2::execReTriggerAttack },
			{ "ScratchAttack", &AZombieCharacter_2::execScratchAttack },
			{ "TimerHandleFunc", &AZombieCharacter_2::execTimerHandleFunc },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_GetAttackAnimInstance()
	{
		struct ZombieCharacter_2_eventGetAttackAnimInstance_Parms
		{
			UAnimInstance* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventGetAttackAnimInstance_Parms, ReturnValue), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "GetAttackAnimInstance", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x40020401, sizeof(ZombieCharacter_2_eventGetAttackAnimInstance_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_GetAttackAnimMontage()
	{
		struct ZombieCharacter_2_eventGetAttackAnimMontage_Parms
		{
			UAnimMontage* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventGetAttackAnimMontage_Parms, ReturnValue), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "GetAttackAnimMontage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x40020401, sizeof(ZombieCharacter_2_eventGetAttackAnimMontage_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnAttackCollisionCompBeginOverlap()
	{
		struct ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult = { UE4CodeGen_Private::EPropertyClass::Struct, "SweepResult", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(NewProp_SweepResult_MetaData, ARRAY_COUNT(NewProp_SweepResult_MetaData)) };
			auto NewProp_bFromSweep_SetBit = [](void* Obj){ ((ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms*)Obj)->bFromSweep = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep = { UE4CodeGen_Private::EPropertyClass::Bool, "bFromSweep", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bFromSweep_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex = { UE4CodeGen_Private::EPropertyClass::Int, "OtherBodyIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp = { UE4CodeGen_Private::EPropertyClass::Object, "OtherComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_OtherComp_MetaData, ARRAY_COUNT(NewProp_OtherComp_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor = { UE4CodeGen_Private::EPropertyClass::Object, "OtherActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent = { UE4CodeGen_Private::EPropertyClass::Object, "OverlappedComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_OverlappedComponent_MetaData, ARRAY_COUNT(NewProp_OverlappedComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SweepResult,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bFromSweep,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherBodyIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OverlappedComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "OnAttackCollisionCompBeginOverlap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00440401, sizeof(ZombieCharacter_2_eventOnAttackCollisionCompBeginOverlap_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnAttackCollisionCompEndOverlap()
	{
		struct ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult = { UE4CodeGen_Private::EPropertyClass::Struct, "SweepResult", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(NewProp_SweepResult_MetaData, ARRAY_COUNT(NewProp_SweepResult_MetaData)) };
			auto NewProp_bFromSweep_SetBit = [](void* Obj){ ((ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms*)Obj)->bFromSweep = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep = { UE4CodeGen_Private::EPropertyClass::Bool, "bFromSweep", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bFromSweep_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex = { UE4CodeGen_Private::EPropertyClass::Int, "OtherBodyIndex", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp = { UE4CodeGen_Private::EPropertyClass::Object, "OtherComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_OtherComp_MetaData, ARRAY_COUNT(NewProp_OtherComp_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor = { UE4CodeGen_Private::EPropertyClass::Object, "OtherActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent = { UE4CodeGen_Private::EPropertyClass::Object, "OverlappedComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(NewProp_OverlappedComponent_MetaData, ARRAY_COUNT(NewProp_OverlappedComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SweepResult,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bFromSweep,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherBodyIndex,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OtherActor,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OverlappedComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "OnAttackCollisionCompEndOverlap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00440401, sizeof(ZombieCharacter_2_eventOnAttackCollisionCompEndOverlap_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnHearNoise()
	{
		struct ZombieCharacter_2_eventOnHearNoise_Parms
		{
			APawn* PawnInstigator;
			FVector Location;
			float Volume;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Volume = { UE4CodeGen_Private::EPropertyClass::Float, "Volume", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnHearNoise_Parms, Volume), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location = { UE4CodeGen_Private::EPropertyClass::Struct, "Location", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnHearNoise_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_Location_MetaData, ARRAY_COUNT(NewProp_Location_MetaData)) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PawnInstigator = { UE4CodeGen_Private::EPropertyClass::Object, "PawnInstigator", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnHearNoise_Parms, PawnInstigator), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Volume,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Location,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnInstigator,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "OnHearNoise", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00C40401, sizeof(ZombieCharacter_2_eventOnHearNoise_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_OnSeePlayer()
	{
		struct ZombieCharacter_2_eventOnSeePlayer_Parms
		{
			APawn* pawn;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_pawn = { UE4CodeGen_Private::EPropertyClass::Object, "pawn", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventOnSeePlayer_Parms, pawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pawn,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "OnSeePlayer", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00040401, sizeof(ZombieCharacter_2_eventOnSeePlayer_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_PlayAttackMotion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "PlayAttackMotion", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_ReTriggerAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "ReTriggerAttack", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_ScratchAttack()
	{
		struct ZombieCharacter_2_eventScratchAttack_Parms
		{
			AActor* HitActor;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitActor = { UE4CodeGen_Private::EPropertyClass::Object, "HitActor", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(ZombieCharacter_2_eventScratchAttack_Parms, HitActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HitActor,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "ScratchAttack", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(ZombieCharacter_2_eventScratchAttack_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AZombieCharacter_2_TimerHandleFunc()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AZombieCharacter_2, "TimerHandleFunc", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AZombieCharacter_2_NoRegister()
	{
		return AZombieCharacter_2::StaticClass();
	}
	UClass* Z_Construct_UClass_AZombieCharacter_2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ARyzenBaseCharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_Ryzen,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AZombieCharacter_2_GetAttackAnimInstance, "GetAttackAnimInstance" }, // 3792410621
				{ &Z_Construct_UFunction_AZombieCharacter_2_GetAttackAnimMontage, "GetAttackAnimMontage" }, // 3800044334
				{ &Z_Construct_UFunction_AZombieCharacter_2_OnAttackCollisionCompBeginOverlap, "OnAttackCollisionCompBeginOverlap" }, // 1890504576
				{ &Z_Construct_UFunction_AZombieCharacter_2_OnAttackCollisionCompEndOverlap, "OnAttackCollisionCompEndOverlap" }, // 749556355
				{ &Z_Construct_UFunction_AZombieCharacter_2_OnHearNoise, "OnHearNoise" }, // 350365120
				{ &Z_Construct_UFunction_AZombieCharacter_2_OnSeePlayer, "OnSeePlayer" }, // 2953399095
				{ &Z_Construct_UFunction_AZombieCharacter_2_PlayAttackMotion, "PlayAttackMotion" }, // 3320353828
				{ &Z_Construct_UFunction_AZombieCharacter_2_ReTriggerAttack, "ReTriggerAttack" }, // 2416203845
				{ &Z_Construct_UFunction_AZombieCharacter_2_ScratchAttack, "ScratchAttack" }, // 1670896707
				{ &Z_Construct_UFunction_AZombieCharacter_2_TimerHandleFunc, "TimerHandleFunc" }, // 2482305924
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Zombie/ZombieCharacter_2.h" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackDamage_MetaData[] = {
				{ "Category", "Attacking" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackDamage = { UE4CodeGen_Private::EPropertyClass::Float, "AttackDamage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, AttackDamage), METADATA_PARAMS(NewProp_AttackDamage_MetaData, ARRAY_COUNT(NewProp_AttackDamage_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScratchDamageType_MetaData[] = {
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_ScratchDamageType = { UE4CodeGen_Private::EPropertyClass::Class, "ScratchDamageType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, ScratchDamageType), Z_Construct_UClass_UDamageType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(NewProp_ScratchDamageType_MetaData, ARRAY_COUNT(NewProp_ScratchDamageType_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AnimInstance_MetaData[] = {
				{ "Category", "ZombieCharacter_2" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AnimInstance = { UE4CodeGen_Private::EPropertyClass::Object, "AnimInstance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000030001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, AnimInstance), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(NewProp_AnimInstance_MetaData, ARRAY_COUNT(NewProp_AnimInstance_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackAnimMontage_MetaData[] = {
				{ "Category", "Attack" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackAnimMontage = { UE4CodeGen_Private::EPropertyClass::Object, "AttackAnimMontage", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, AttackAnimMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(NewProp_AttackAnimMontage_MetaData, ARRAY_COUNT(NewProp_AttackAnimMontage_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackSound_MetaData[] = {
				{ "Category", "Sound" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackSound = { UE4CodeGen_Private::EPropertyClass::Object, "AttackSound", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, AttackSound), Z_Construct_UClass_USoundCue_NoRegister, METADATA_PARAMS(NewProp_AttackSound_MetaData, ARRAY_COUNT(NewProp_AttackSound_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZombieType_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
				{ "ToolTip", "???? \xc5\xb8??" },
			};
#endif
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ZombieType = { UE4CodeGen_Private::EPropertyClass::Enum, "ZombieType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, ZombieType), Z_Construct_UEnum_Ryzen_EZombieType, METADATA_PARAMS(NewProp_ZombieType_MetaData, ARRAY_COUNT(NewProp_ZombieType_MetaData)) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ZombieType_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BehaviorTree_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BehaviorTree = { UE4CodeGen_Private::EPropertyClass::Object, "BehaviorTree", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, BehaviorTree), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(NewProp_BehaviorTree_MetaData, ARRAY_COUNT(NewProp_BehaviorTree_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackCollisionComp_MetaData[] = {
				{ "Category", "Attack" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackCollisionComp = { UE4CodeGen_Private::EPropertyClass::Object, "AttackCollisionComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a0009, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, AttackCollisionComp), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(NewProp_AttackCollisionComp_MetaData, ARRAY_COUNT(NewProp_AttackCollisionComp_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HearingSenseTimeOut_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
				{ "ToolTip", "?\xd2\xb8??? ?????\xcf\xb0? ?? ???? \xc5\xbd???\xcf\xb4? ?\xc3\xb0? 6??" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HearingSenseTimeOut = { UE4CodeGen_Private::EPropertyClass::Float, "HearingSenseTimeOut", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, HearingSenseTimeOut), METADATA_PARAMS(NewProp_HearingSenseTimeOut_MetaData, ARRAY_COUNT(NewProp_HearingSenseTimeOut_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SightSenseTimeOut_MetaData[] = {
				{ "Category", "AI" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
				{ "ToolTip", "\xc5\xb8???? \xc3\xa3?? ???\xcf\xb4\xc2\xb5? ?\xc9\xb8??? ?\xc3\xb0? 2.5??" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SightSenseTimeOut = { UE4CodeGen_Private::EPropertyClass::Float, "SightSenseTimeOut", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, SightSenseTimeOut), METADATA_PARAMS(NewProp_SightSenseTimeOut_MetaData, ARRAY_COUNT(NewProp_SightSenseTimeOut_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PawnSensingComp_MetaData[] = {
				{ "Category", "AI" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Zombie/ZombieCharacter_2.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PawnSensingComp = { UE4CodeGen_Private::EPropertyClass::Object, "PawnSensingComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a0009, 1, nullptr, STRUCT_OFFSET(AZombieCharacter_2, PawnSensingComp), Z_Construct_UClass_UPawnSensingComponent_NoRegister, METADATA_PARAMS(NewProp_PawnSensingComp_MetaData, ARRAY_COUNT(NewProp_PawnSensingComp_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AttackDamage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ScratchDamageType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AnimInstance,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AttackAnimMontage,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AttackSound,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZombieType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZombieType_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BehaviorTree,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_AttackCollisionComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HearingSenseTimeOut,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SightSenseTimeOut,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PawnSensingComp,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AZombieCharacter_2>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AZombieCharacter_2::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AZombieCharacter_2, 3834441244);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AZombieCharacter_2(Z_Construct_UClass_AZombieCharacter_2, &AZombieCharacter_2::StaticClass, TEXT("/Script/Ryzen"), TEXT("AZombieCharacter_2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZombieCharacter_2);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
