// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCCharacter.h"
#include "FPS_Game.h"



/* AI Include */
#include "Perception/PawnSensingComponent.h"


// Sets default values
ANPCCharacter::ANPCCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{


	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(60.0f);
	PawnSensingComp->SightRadius = 2000;
	PawnSensingComp->HearingThreshold = 600;
	PawnSensingComp->LOSHearingThreshold = 1200;

	AttackCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("AttackCollision"));
	AttackCollisionComp->SetRelativeLocation(FVector(45, 0, 25));
	AttackCollisionComp->SetCapsuleHalfHeight(60);
	AttackCollisionComp->SetCapsuleRadius(35, false);
	AttackCollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	AttackCollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	AttackCollisionComp->SetupAttachment(GetCapsuleComponent());

	TalkCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TalkCollision"));
	TalkCollisionComp->SetCapsuleHalfHeight(60);
	TalkCollisionComp->SetCapsuleRadius(150, false);
	TalkCollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	TalkCollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	TalkCollisionComp->SetupAttachment(GetCapsuleComponent());

	bSensedTarget = false;
	bHeardTarget = false;

	//���� Ÿ������ �����ϰ� �����ϴµ� �ɸ��� �ð� 2.5��
	SightSenseTimeOut = 10.0f;
	HearingSenseTimeOut = 6.0f;

	//���� �ð� ����� ����
	LastSeenTime = 0.0f;
	LastHeardTime = 0.0f;

	DefaultMaxWalkSpeed = 0.0f;

	AttackCooltime = 1.5f;

	bIsQuestNPC = false;
	bIsAmmoNPC = false;
	bIsHealNPC = false;
}

// Called when the game starts or when spawned
void ANPCCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		PawnSensingComp->OnSeePawn.AddDynamic(this, &ANPCCharacter::OnSeeZombie);

		PawnSensingComp->OnHearNoise.AddDynamic(this, &ANPCCharacter::OnHearNoise);
	}
	if (AttackCollisionComp)
	{
		AttackCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ANPCCharacter::OnAttackCollisionCompBeginOverlap);
	}

	if (TalkCollisionComp)
	{
		TalkCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ANPCCharacter::OnTalkCollisionCompBeginOverlap);//&AFlockingPlayerController::OpenWidget);

		TalkCollisionComp->OnComponentEndOverlap.AddDynamic(this, &ANPCCharacter::OnTalkCollisionCompEndOverlap);//&AFlockingPlayerController::ClosedWidget);
	}

	ANPCController* NPC = Cast<ANPCController>(GetController());
	NPC->SetIsRunAway(true);

	DefaultMaxWalkSpeed = GetMovementComponent()->GetMaxSpeed();
}

// Called every frame
void ANPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	/* 2.5�� ���� �÷��̾ �i�ٰ� �÷��̾ �i�� ���ϸ� Ÿ�� �ʱ�ȭ */
	if (bSensedTarget && (GetWorld()->TimeSeconds - LastSeenTime) > SightSenseTimeOut
		&& (GetWorld()->TimeSeconds - LastHeardTime) > HearingSenseTimeOut)
	{
		ANPCController* AIController = Cast<ANPCController>(GetController());
		if (AIController)
		{
			bSensedTarget = false;
			/* Ÿ�� ���� */
			AIController->SetTargetEnemy(nullptr);

			bHeardTarget = false;

			Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = DefaultMaxWalkSpeed;
		}
	}

	if (GetWorld())
	{
		AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode && GameMode->Complete_Quest[0] == true)
		{
			ANPCController* NPC = Cast<ANPCController>(GetController());
			NPC->SetIsRunAway(false);
		}
	}
}


void ANPCCharacter::OnAttackCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	/*TimerHandle_AttackTimer.Invalidate();

	ScratchAttack(OtherActor);

	GetWorldTimerManager().SetTimer(TimerHandle_AttackTimer, this, &ANPCCharacter::ReTriggerAttack, AttackCooltime, true);*/

}

void ANPCCharacter::OnAttackCollisionCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ANPCCharacter::OnTalkCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//ANPCController* Controller = Cast<ANPCController>(GetController());
	//APlayerCharacter *SensedPlayer = Cast<APlayerCharacter>(OtherActor);
	////APawn* SensedPlayer = Cast<APawn>(OtherActor);
	//Controller->SetTargetPlayer(SensedPlayer);
	if (OtherActor->ActorHasTag("Player"))
	{
		APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
		ARPlayerController* PlayerController = Cast<ARPlayerController>(Player->GetController());
		AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());


		if (bIsQuestNPC && !bIsAmmoNPC && !bIsHealNPC)
		{
			//���� ����Ʈ�� �Ϸ� �� ���, ����Ʈâ�� �ݴ´�.
			if (GameMode->GetQuestNum() < 3 && GameMode->Complete_Quest[GameMode->GetQuestNum()] == true)
			{

			}

			//Tutorial Quest Clear
			if (GameMode->GetQuestNum() == 0 && PlayerController->GetQuestScore() == 1)
			{
				Player->SetCurrentQuestDeActivate(GameMode->GetQuestNum());
				GameMode->SetCompleteQuest(0);
			}
			//Stage1 Quest Clear
			if (GameMode->GetQuestNum() == 1 && PlayerController->GetQuestScore() == 5)
			{
				Player->SetCurrentQuestDeActivate(GameMode->GetQuestNum());
				GameMode->SetCompleteQuest(1);
			}

			PlayerController->SetTalkNPCType(0);


			//Quest ���� ���� ������ �־����
			//Quest Script Widget Open
			PlayerController->OpenWidget(1);
		}
		else if (!bIsQuestNPC && !bIsAmmoNPC && bIsHealNPC)
		{
			PlayerController->SetTalkNPCType(1);

			//Heal Widget Open
			PlayerController->OpenWidget(2);
		}
		else if (!bIsQuestNPC && bIsAmmoNPC && !bIsHealNPC)
		{
			PlayerController->SetTalkNPCType(2);

			//Ammmo WIdget Open
			PlayerController->OpenWidget(3);
		}

		/*APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		ARPlayerController* Controller = Cast<ARPlayerController>(OurPlayerController);*/
		if (PlayerController)
		{
			if (PlayerController->bTurnViewTarget == true)
			{
				StopAllAnimation();

				if (SurpriseAnimMontage)
					PlayAnimMontage(SurpriseAnimMontage);
			}
			else
			{
				StopAllAnimation();

				if (TalkAnimMontage)
					PlayAnimMontage(TalkAnimMontage);
			}
		}
	}
	
}

void ANPCCharacter::OnTalkCollisionCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	/*ANPCController* Controller = Cast<ANPCController>(GetController());
	Controller->SetTargetPlayer(nullptr);*/

	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	ARPlayerController* PlayerController = Cast<ARPlayerController>(Player->GetController());
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

	PlayerController->CloseWidget(1);

	StopAllAnimation();
}

void ANPCCharacter::OnSeeZombie(APawn* pawn)
{
	if (!bSensedTarget)
	{

	}

	if (!bSensedTarget)
	{
		//AuidoLoop
	}

	//Ÿ���� �߰� �� �� ���� �ð��� ����
	LastSeenTime = GetWorld()->GetTimeSeconds();
	bSensedTarget = true;

	ANPCController* AIController = Cast<ANPCController>(GetController());
	AZombieCharacter* SensedPawn = Cast<AZombieCharacter>(pawn);
	if (AIController)
	{
		AIController->SetTargetEnemy(SensedPawn);
		//167.0f == Zombie Run
		Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = 167.0f;
	}
}

void ANPCCharacter::OnHearNoise(APawn* PawnInstigator, const FVector& Location, float Volume)
{
	bSensedTarget = true;
	LastHeardTime = GetWorld()->GetTimeSeconds();

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Noise Check!"));

	ANPCController* AIController = Cast<ANPCController>(GetController());
	if (AIController)
	{
		AIController->SetTargetEnemy(PawnInstigator);
	}
}

void ANPCCharacter::ScratchAttack(AActor* HitActor)
{
	if (LastAttackTime > GetWorld()->GetTimeSeconds() - AttackCooltime)
	{
		if (!TimerHandle_AttackTimer.IsValid())
		{

		}
		return;
	}

	//AZombieCharacter_2* other = Cast<AZombieCharacter_2>(OtherComp);
	if (HitActor && HitActor != this) {

		if (AttackAnimMontage != NULL) {
			AnimInstance = this->GetMesh()->GetAnimInstance();
			if (AnimInstance != NULL) {
				LastAttackTime = GetWorld()->GetTimeSeconds();


				PlayAttackMotion();
			}

		}
	}
}

void ANPCCharacter::ReTriggerAttack()
{
	TArray<AActor*> OverlapActor;
	//Attack Collision�� Timer�� ReTriggerAttack�� ���� �� �� ����, Overlap�� ���͸� �������
	AttackCollisionComp->GetOverlappingActors(OverlapActor, AZombieCharacter::StaticClass());
	for (int32 i = 0; i < OverlapActor.Num(); i++)
	{
		AZombieCharacter* OverlappingPawn = Cast<AZombieCharacter>(OverlapActor[i]);
		if (OverlappingPawn)
		{
			ScratchAttack(OverlappingPawn);
		}
	}
	if (OverlapActor.Num() == 0)
	{
		TimerHandle_AttackTimer.Invalidate();
	}
}

void ANPCCharacter::PlayAttackMotion()
{
	if (AttackAnimMontage)
	{
		AnimInstance->Montage_Play(AttackAnimMontage, 2.5f);
	}
}


void ANPCCharacter::TimerHandleFunc()
{
	//Timer�Լ�. AttackTimer�� Invalidate ���� �ʾҴٸ�, AttackCooltime ���� ReTriggerAttack �Լ��� ������.
	GetWorldTimerManager().SetTimer(TimerHandle_AttackTimer, this, &ANPCCharacter::ReTriggerAttack, AttackCooltime, true);
}

void ANPCCharacter::PlayTalkMotion()
{
	if (TalkAnimMontage)
	{
		AnimInstance->Montage_Play(TalkAnimMontage, 2.5f);
	}
}

void ANPCCharacter::PlayAngryMotion()
{
	if (AngryAnimMontage)
	{
		AnimInstance->Montage_Play(AngryAnimMontage, 2.5f);
	}
}

void ANPCCharacter::PlayHappyMotion()
{
	if (HappyAnimMontage)
	{
		AnimInstance->Montage_Play(HappyAnimMontage, 2.5f);
	}
}

void ANPCCharacter::PlaySurpriseMotion()
{
	if (SurpriseAnimMontage)
	{
		//AnimInstance->Montage_Play(SurpriseAnimMontage, 2.5f);
		PlayAnimMontage(SurpriseAnimMontage);
	}
}

void ANPCCharacter::StopAllAnimation()
{
	USkeletalMeshComponent* Mesh = GetMesh();
	if (Mesh && Mesh->AnimScriptInstance)
	{
		Mesh->AnimScriptInstance->Montage_Stop(0.0f);
	}
}