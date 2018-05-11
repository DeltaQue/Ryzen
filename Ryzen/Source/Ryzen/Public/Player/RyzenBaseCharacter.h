// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Character.h"
#include "StructClass.h"
#include "RyzenBaseCharacter.generated.h"

//UCLASS(ABSTRACT)�� �� Ŭ������ �߻� Ŭ�����̹Ƿ� ��üȭ �� �� ���ٴ� ���̴�.
UCLASS(ABSTRACT)
class RYZEN_API ARyzenBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARyzenBaseCharacter(const class FObjectInitializer& ObjectInitializer);
	
private:
	//Pawn���� Soundüũ�ϱ� ���� ������Ʈ
	UPawnNoiseEmitterComponent* NoiseEmitterComp;

public:
	//ĳ���� ���� ����, 
	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* SoundTakeHit;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* SoundDeath;

	//ĳ���� �������ͽ�
	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
		float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
		float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "PlayerCondition")
		bool IsAlive() const;

	/* ���� ī�޶��� Pitch/Yaw �˻� */
	UFUNCTION(BlueprintCallable, Category = "Targeting")
		FRotator GetAimOffsets() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCondition")
		float Health;

	bool bisDying;
	
};
