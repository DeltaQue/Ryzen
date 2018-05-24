// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/DamageType.h"
#include "RDamageType.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API URDamageType : public UDamageType
{
	GENERATED_BODY()

		URDamageType(const FObjectInitializer& objectInitializer);

	/* Headshot ������ */
	UPROPERTY(EditDefaultsOnly)
		float HeadDmgModifier;

	UPROPERTY(EditDefaultsOnly)
		float LimbDmgModifier;

public:


	float GetHeadDamageModifier();

	float GetLimbDamageModifier();
	
	
};
