// Fill out your copyright notice in the Description page of Project Settings.

#include "ZombieCharacter_2.h"
#include "ZombieAIController.h"
#include "RyzenBaseCharacter.h"

/* AI Include */
#include "Perception/PawnSensingComponent.h"


// Sets default values
AZombieCharacter_2::AZombieCharacter_2(const class FObjectInitializer& ObjectInitializer)
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

	AttackCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AttackCollision"));
	AttackCollisionComp->SetRelativeLocation(FVector(45, 0, 25));
	AttackCollisionComp->SetCapsuleHalfHeight(60);
	AttackCollisionComp->SetCapsuleRadius(35, false);
	AttackCollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	AttackCollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	AttackCollisionComp->SetupAttachment(GetCapsuleComponent());


	GetMovementComponent()->NavAgentProps.AgentRadius = 42;
	GetMovementComponent()->NavAgentProps.AgentHeight = 192;

	//�⺻ ü�� 100
	Health = 100;

	bSensedTarget = false;
	bHeardTarget = false;

	//���� Ÿ������ �����ϰ� �����ϴµ� �ɸ��� �ð� 2.5��
	SenseTimeOut = 2.5f;

	//���� �ð� ����� ����
	LastSeenTime = 0.0f;
	LastHeardTime = 0.0f;

	bOverlapAttackCollision = false;

	DefaultMaxWalkSpeed = 0.0f;
}


void AZombieCharacter_2::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AZombieCharacter_2::OnSeePlayer);

		PawnSensingComp->OnHearNoise.AddDynamic(this, &AZombieCharacter_2::OnHearNoise);
	}
	if (AttackCollisionComp)
	{
		AttackCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AZombieCharacter_2::OnAttackCollisionCompBeginOverlap);
	}

	DefaultMaxWalkSpeed = GetMovementComponent()->GetMaxSpeed();
}


void AZombieCharacter_2::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	/* 2.5�� ���� �÷��̾ �i�ٰ� �÷��̾ �i�� ���ϸ� Ÿ�� �ʱ�ȭ */
	if (bSensedTarget && (GetWorld()->TimeSeconds - LastSeenTime) > SenseTimeOut
		&& (GetWorld()->TimeSeconds - LastHeardTime) > SenseTimeOut)
	{
		AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
		if (AIController)
		{
			bSensedTarget = false;
			/* Ÿ�� ���� */
			AIController->SetTargetEnemy(nullptr);

			bHeardTarget = false;

			AIController->SetReconLocation(FVector(-1, -1, -1));

			Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed;
		}
	}

	IsDeath();
}



void AZombieCharacter_2::OnSeePlayer(APawn* Pawn)
{
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{

	}

	//Ÿ���� �߰� �� �� ���� �ð��� ����
	LastSeenTime = GetWorld()->GetTimeSeconds();
	bSensedTarget = true;

	AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
	ARyzenBaseCharacter* SensedPawn = Cast<ARyzenBaseCharacter>(Pawn);
	if (AIController && SensedPawn->IsAlive())
	{
		AIController->SetTargetEnemy(SensedPawn);
		//167.0f == Zombie Run
		Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = 167.0f;
	}
}

void AZombieCharacter_2::OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume) {
	if (!IsAlive())
	{
		return;
	}

	if (!bSensedTarget)
	{
		//AudioLoop(true);
	}

	bSensedTarget = true;
	LastHeardTime = GetWorld()->GetTimeSeconds();

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Noise Check!"));

	AZombieAIController* AIController = Cast<AZombieAIController>(GetController());
	if (AIController)
	{
		AIController->SetTargetEnemy(PawnInstigator);
		AIController->SetReconLocation(Location);
	}
}

void AZombieCharacter_2::SetZombieType(EZombieType NewType) 
{
	ZombieType = NewType;

	AZombieAIController* ZombieController = Cast<AZombieAIController>(GetController());
	if (ZombieController)
	{
		ZombieController->SetBlackboardZombieType(NewType);
	}
}


void AZombieCharacter_2::OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//AZombieCharacter_2* other = Cast<AZombieCharacter_2>(OtherComp);
	if (OtherActor && OtherActor != this && IsAlive()) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Begin Attack"));
		if (AttackAnimMontage != NULL) {
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Attack Loop"));
			AnimInstance = this->GetMesh()->GetAnimInstance();
			if (AnimInstance != NULL) {
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("End Attack"));
				//PlayAnimMontage(AttackAnimMontage);
				AnimInstance->Montage_Play(AttackAnimMontage, 2.5f);
				bOverlapAttackCollision = true;
			}

		}
	}

	
}

void AZombieCharacter_2::OnAttackCollisionCompEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	bOverlapAttackCollision = false;
}

bool AZombieCharacter_2::DamageHit(uint8 damage) {
	if (this->Health - damage > 0) {
		this->Health -= damage;
		if (this->IsAlive()) {
			return true;
		}

	}

	return false;
}

void AZombieCharacter_2::IsDeath() {
	if (!this->IsAlive())
		Destroy();
}

bool AZombieCharacter_2::GetOverlapAttackCollision() const{	return bOverlapAttackCollision; }

UAnimInstance* AZombieCharacter_2::GetAttackAnimInstance() const { return AnimInstance; }

UAnimMontage* AZombieCharacter_2::GetAttackAnimMontage() const { return AttackAnimMontage; }