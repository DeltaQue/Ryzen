// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DamageType.h"
#include "PlayerDamageType.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API UPlayerDamageType : public UDamageType
{
	GENERATED_BODY()

	UPlayerDamageType(const FObjectInitializer& ObjectInitializer);

	/* 
	��弦 ������ 2��
	�ٵ� ������ 1��
	��Ÿ ���� ������ 0.5��
	*/
	UPROPERTY(EditDefaultsOnly)
		float HeadDmgModifier;

	UPROPERTY(EditDefaultsOnly)
		float LimbDmgModifier;

	UPROPERTY(EditDefaultsOnly)
		float BodyDmgModifier;

public:

	bool GetCanDieFrom();

	float GetHeadDamageModifier();

	float GetLimbDamageModifier();

	float GetBodyDamageModifier();
};
