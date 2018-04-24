// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef RYZEN_ManualPickup_generated_h
#error "ManualPickup.generated.h already included, missing '#pragma once' in ManualPickup.h"
#endif
#define RYZEN_ManualPickup_generated_h

#define Ryzen_Source_Ryzen_ManualPickup_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnEndOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverlapCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->OverlapCheck(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_ManualPickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnEndOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnBeginOverlap) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverlapCheck) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->OverlapCheck(); \
		P_NATIVE_END; \
	}


#define Ryzen_Source_Ryzen_ManualPickup_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAManualPickup(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AManualPickup(); \
public: \
	DECLARE_CLASS(AManualPickup, AInteractable, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AManualPickup) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_ManualPickup_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAManualPickup(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_AManualPickup(); \
public: \
	DECLARE_CLASS(AManualPickup, AInteractable, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(AManualPickup) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_ManualPickup_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AManualPickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AManualPickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AManualPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AManualPickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AManualPickup(AManualPickup&&); \
	NO_API AManualPickup(const AManualPickup&); \
public:


#define Ryzen_Source_Ryzen_ManualPickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AManualPickup(AManualPickup&&); \
	NO_API AManualPickup(const AManualPickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AManualPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AManualPickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AManualPickup)


#define Ryzen_Source_Ryzen_ManualPickup_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollectionSphere() { return STRUCT_OFFSET(AManualPickup, CollectionSphere); } \
	FORCEINLINE static uint32 __PPO__PickupMesh() { return STRUCT_OFFSET(AManualPickup, PickupMesh); } \
	FORCEINLINE static uint32 __PPO__ItemID() { return STRUCT_OFFSET(AManualPickup, ItemID); }


#define Ryzen_Source_Ryzen_ManualPickup_h_12_PROLOG
#define Ryzen_Source_Ryzen_ManualPickup_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_ManualPickup_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_ManualPickup_h_15_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_ManualPickup_h_15_INCLASS \
	Ryzen_Source_Ryzen_ManualPickup_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_ManualPickup_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_ManualPickup_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_ManualPickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_ManualPickup_h_15_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_ManualPickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_ManualPickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
