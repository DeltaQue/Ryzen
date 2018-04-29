// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RYZEN_StructClass_generated_h
#error "StructClass.generated.h already included, missing '#pragma once' in StructClass.h"
#endif
#define RYZEN_StructClass_generated_h

#define Ryzen_Source_Ryzen_Public_StructClass_h_15_RPC_WRAPPERS
#define Ryzen_Source_Ryzen_Public_StructClass_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Ryzen_Source_Ryzen_Public_StructClass_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUStructClass(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_UStructClass(); \
public: \
	DECLARE_CLASS(UStructClass, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(UStructClass) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_StructClass_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUStructClass(); \
	friend RYZEN_API class UClass* Z_Construct_UClass_UStructClass(); \
public: \
	DECLARE_CLASS(UStructClass, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/Ryzen"), NO_API) \
	DECLARE_SERIALIZER(UStructClass) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Ryzen_Source_Ryzen_Public_StructClass_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UStructClass(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UStructClass) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UStructClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UStructClass); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UStructClass(UStructClass&&); \
	NO_API UStructClass(const UStructClass&); \
public:


#define Ryzen_Source_Ryzen_Public_StructClass_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UStructClass(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UStructClass(UStructClass&&); \
	NO_API UStructClass(const UStructClass&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UStructClass); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UStructClass); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UStructClass)


#define Ryzen_Source_Ryzen_Public_StructClass_h_15_PRIVATE_PROPERTY_OFFSET
#define Ryzen_Source_Ryzen_Public_StructClass_h_12_PROLOG
#define Ryzen_Source_Ryzen_Public_StructClass_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_RPC_WRAPPERS \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_INCLASS \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Ryzen_Source_Ryzen_Public_StructClass_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_PRIVATE_PROPERTY_OFFSET \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_INCLASS_NO_PURE_DECLS \
	Ryzen_Source_Ryzen_Public_StructClass_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Ryzen_Source_Ryzen_Public_StructClass_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
