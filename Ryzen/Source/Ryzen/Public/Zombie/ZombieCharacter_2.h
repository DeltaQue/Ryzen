// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/RyzenBaseCharacter.h"
#include "StructClass.h"
#include "ZombieCharacter_2.generated.h"


UCLASS()
class RYZEN_API AZombieCharacter_2 : public ARyzenBaseCharacter
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
		class UPawnSensingComponent* PawnSensingComp;

	//Ÿ���� ã�� ���ϴµ� �ɸ��� �ð� 2.5��
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		float SenseTimeOut;

	/* Ÿ���� �i�ٰ� SenseTimeOut�� ������ Ÿ���� �����ϴ¿� */
	bool bSensedTarget;
	//Ÿ���� �߰� �� �� ���� �ð��� ����
	float LastSeenTime;
public:
	// Sets default values for this character's properties
	AZombieCharacter_2(const class FObjectInitializer& ObjectInitializer);

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void OnSeePlayer(APawn* pawn);
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		class UBehaviorTree* BehaviorTree;

	//���� Ÿ��
	UPROPERTY(EditAnywhere, Category = "AI")
		EZombieType ZombieType;

	void SetBotType(EZombieType NewType);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Attack")
		UAnimMontage* ActtackAnimMontage;

	
};
