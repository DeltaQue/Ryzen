// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPS_GameStruct.h"
#include "Character/BaseCharacter.h"
#include "NPCCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API ANPCCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
	

private:
	UFUNCTION()
		void OnTalkCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnTalkCollisionCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);

	/////////////////////


	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	//�Ҹ��� �����ϰ� �� ���� Ž���ϴ� �ð� 6��
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float HearingSenseTimeOut;

	UPROPERTY(VisibleAnywhere, Category = "Talk")
		class UCapsuleComponent* TalkCollisionComp;


	void StopAllAnimation();

	/* Ÿ���� �i�ٰ� SenseTimeOut�� ������ Ÿ���� �����ϴ¿� */
	bool bSensedTarget;
	bool bHeardTarget;

	//Ÿ���� �߰� �� �� ���� �ð��� ����
	float LastSeenTime;
	float LastHeardTime;

	float DefaultMaxWalkSpeed;

public:
	// Sets default values for this character's properties
	ANPCCharacter(const class FObjectInitializer& ObjectInitializer);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		UAnimMontage* AttackAnimMontage;

	UPROPERTY(VisibleDefaultsOnly)
		class UAnimInstance* AnimInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Talk")
		UAnimMontage* TalkAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Talk")
		UAnimMontage* SurpriseAnimMontage;


	//NPC Type
	UPROPERTY(EditDefaultsOnly, Category = "NPC")
		bool bIsQuestNPC;

	UPROPERTY(EditDefaultsOnly, Category = "NPC")
		bool bIsHealNPC;

	UPROPERTY(EditDefaultsOnly, Category = "NPC")
		bool bIsAmmoNPC;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	void PlayTalkMotion();

	void PlaySurpriseMotion();

	UPROPERTY(EditAnywhere, Category = "AI")
		ENPCType NPCType;
	
};
