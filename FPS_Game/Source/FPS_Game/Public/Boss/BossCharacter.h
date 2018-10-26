// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FPS_Game.h"
#include "Character/BaseCharacter.h"
#include "BossCharacter.generated.h"

class UAnimMontage;
class UAudioComponent;
class USoundCue;

UCLASS()
class FPS_GAME_API ABossCharacter : public ABaseCharacter
{
	GENERATED_BODY()


private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	UFUNCTION()
		void OnSeePlayer(APawn* pawn);



	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	/* Ÿ���� �i�ٰ� SenseTimeOut�� ������ Ÿ���� �����ϴ¿� */
	bool bSensedTarget;
	bool bHeardTarget;
	bool bPlayedScream;

	//Ÿ���� �߰� �� �� ���� �ð��� ����
	float LastSeenTime;
	float LastHeardTime;

	float SightSenseTimeOut;
	float HearingSenseTimeOut;

	float DefaultMaxWalkSpeed;

public:
	// Sets default values for this character's properties
	ABossCharacter(const class FObjectInitializer& ObjectInitializer);



	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

protected:
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* AttackAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* ScreamAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerChaseSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerWanderingSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* IdleSoundCue;


};
