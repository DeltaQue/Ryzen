// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FPS_Game.h"
#include "Character/BaseCharacter.h"
#include "Components/WidgetComponent.h"
#include "ZombieCharacter.generated.h"


class UAnimMontage;
class UAudioComponent;
class USoundCue;

UCLASS()
class FPS_GAME_API AZombieCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	

private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	//UPROPERTY(EditDefaultsOnly, Category = "HUD")
	//	UWidgetComponent* MyWidget;

	UFUNCTION()
		void OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
		void OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void ScratchAttack(AActor* HitActor);

	UFUNCTION(BlueprintCallable, Category = "Attack")
		void ReTriggerAttack();

	//Ÿ���� ã�� ���ϴµ� �ɸ��� �ð� 2.5��
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float SightSenseTimeOut;

	//�Ҹ��� �����ϰ� �� ���� Ž���ϴ� �ð� 6��
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float HearingSenseTimeOut;

	
	void AudioLoopUpdate(bool bNewSensedTarget);
	void Attack_TakeDamage(AActor* HitActor);


	float LastAttackTime;
	float AttackCooltime;

	/* Ÿ���� �i�ٰ� SenseTimeOut�� ������ Ÿ���� �����ϴ¿� */
	bool bSensedTarget;
	bool bHeardTarget;
	bool bPlayedScream;

	//Ÿ���� �߰� �� �� ���� �ð��� ����
	float LastSeenTime;
	float LastHeardTime;

	float DefaultMaxWalkSpeed;

	FTimerHandle TimerHandle_AttackTimer;
	FTimerHandle TimerHandle_ScreamTimer;

	FTimerDelegate ScreamTimerDelegate;

public:
	// Sets default values for this character's properties
	AZombieCharacter(const class FObjectInitializer& ObjectInitializer);

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void OnSeePlayer(APawn* pawn);

	UFUNCTION()
		void OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume);

	UPROPERTY(VisibleAnywhere, Category = "Attack")
		UCapsuleComponent* AttackCollisionComp;

	UPROPERTY(VisibleAnywhere, Category = "Sound")
		UAudioComponent* AudioLoopComp;

	//ü���� 0���Ϸ� ���������� �ൿ�� ����, ragdoll ��..
	void IsDeath();

public:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	//���� Ÿ��
	UPROPERTY(EditAnywhere, Category = "AI")
		EZombieType ZombieType;

	UFUNCTION()
		UAnimInstance* GetAttackAnimInstance() const;

	UFUNCTION()
		UAnimMontage* GetAttackAnimMontage() const;

	UFUNCTION()
		float PlayAttackMotion();

	UFUNCTION()
		void TimerHandleFunc();

	


	void SetZombieType(EZombieType NewType);

	bool DamageHit(uint8 damage);

	bool GetIsBoss() const;

	UFUNCTION()
		void TargetChase(APawn* pawn);
protected:
	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* AttackAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* AttackAnim2Montage;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
		UAnimMontage* ScreamAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerChaseSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* PlayerWanderingSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* IdleSoundCue;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
		USoundCue* AttackSound;

	UPROPERTY(EditDefaultsOnly, Category = "ZombieState")
		bool IsBoss;


	class UAnimInstance* AnimInstance;

	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		TSubclassOf<UDamageType> ScratchDamageType;

	UPROPERTY(EditDefaultsOnly, Category = "Attacking")
		float AttackDamage;
	
	
};
