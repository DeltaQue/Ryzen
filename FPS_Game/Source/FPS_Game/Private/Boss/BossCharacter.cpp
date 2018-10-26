// Fill out your copyright notice in the Description page of Project Settings.

#include "BossCharacter.h"
#include "BossAIController.h"
#include "BaseCharacter.h"

/* AI Include */
#include "Perception/PawnSensingComponent.h"

ABossCharacter::ABossCharacter(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	//�þ߿� ���� �ִ��� üũ�ϴ� ������Ʈ
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;
	PawnSensingComp->HearingThreshold = 600;
	PawnSensingComp->LOSHearingThreshold = 1200;

	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f, false);
	GetCapsuleComponent()->SetCapsuleRadius(42.0f);


	GetMovementComponent()->NavAgentProps.AgentRadius = 42;
	GetMovementComponent()->NavAgentProps.AgentHeight = 192;

	bSensedTarget = false;
	bHeardTarget = false;
	bPlayedScream = false;

	//���� Ÿ������ �����ϰ� �����ϴµ� �ɸ��� �ð� 2.5��
	SightSenseTimeOut = 2.5f;
	HearingSenseTimeOut = 6.0f;

	//���� �ð� ����� ����
	LastSeenTime = 0.0f;
	LastHeardTime = 0.0f;

	DefaultMaxWalkSpeed = 0.0f;
}


void ABossCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ABossCharacter::OnSeePlayer);

		//PawnSensingComp->OnHearNoise.AddDynamic(this, &AZombieCharacter::OnHearNoise);
	}

	DefaultMaxWalkSpeed = GetMovementComponent()->GetMaxSpeed();
}


void ABossCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* 2.5�� ���� �÷��̾ �i�ٰ� �÷��̾ �i�� ���ϸ� Ÿ�� �ʱ�ȭ */
	if (bSensedTarget && (GetWorld()->TimeSeconds - LastSeenTime) > SightSenseTimeOut
		&& (GetWorld()->TimeSeconds - LastHeardTime) > HearingSenseTimeOut)
	{
		ABossAIController* AIController = Cast<ABossAIController>(GetController());
		if (AIController)
		{
			bSensedTarget = false;
			bPlayedScream = false;
			bHeardTarget = false;

			/* Ÿ�� ���� */
			AIController->SetTargetEnemy(nullptr);

			Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed;
		}
	}

}


void ABossCharacter::OnSeePlayer(APawn* Pawn)
{
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{
		//AudioLoopUpdate(true);
	}

	float Duration = 0.0f;

	if (ScreamAnimMontage && !bPlayedScream)
	{
		Duration = PlayAnimMontage(ScreamAnimMontage);
		bPlayedScream = true;

		if (Duration <= 0.f)
		{
			Duration = 0.5f;
		}

		/*FTimerHandle UniqueHandle;
		FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &ABossCharacter::TargetChase, Pawn);
		GetWorldTimerManager().SetTimer(UniqueHandle, RespawnDelegate, Duration, false);*/
	}

}