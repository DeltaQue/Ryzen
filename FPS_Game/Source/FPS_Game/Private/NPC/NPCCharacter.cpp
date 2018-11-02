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

	TalkCollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TalkCollision"));
	TalkCollisionComp->SetCapsuleHalfHeight(60);
	TalkCollisionComp->SetCapsuleRadius(150, false);
	TalkCollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	TalkCollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	TalkCollisionComp->SetupAttachment(GetCapsuleComponent());

	bSensedTarget = false;
	bHeardTarget = false;

	//���� Ÿ������ �����ϰ� �����ϴµ� �ɸ��� �ð� 2.5��
	HearingSenseTimeOut = 6.0f;

	//���� �ð� ����� ����
	LastSeenTime = 0.0f;
	LastHeardTime = 0.0f;

	DefaultMaxWalkSpeed = 0.0f;

	NPCType = ENPCType::Idle;

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
		PawnSensingComp->OnHearNoise.AddDynamic(this, &ANPCCharacter::OnHearNoise);
	}

	if (TalkCollisionComp)
	{
		TalkCollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ANPCCharacter::OnTalkCollisionCompBeginOverlap);//&AFlockingPlayerController::OpenWidget);

		TalkCollisionComp->OnComponentEndOverlap.AddDynamic(this, &ANPCCharacter::OnTalkCollisionCompEndOverlap);//&AFlockingPlayerController::ClosedWidget);
	}

	ANPCController* Controller = Cast<ANPCController>(GetController());
	Controller->SetNPCType(NPCType);

	DefaultMaxWalkSpeed = GetMovementComponent()->GetMaxSpeed();
}

// Called every frame
void ANPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}



void ANPCCharacter::OnTalkCollisionCompBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
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
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	ARPlayerController* PlayerController = Cast<ARPlayerController>(Player->GetController());
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

	PlayerController->CloseWidget(1);

	StopAllAnimation();


	if (GetWorld())
	{
		AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
		if (GameMode)
		{
			if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(0) - 1 && GameMode->Complete_Quest[0] == false)
			{
				ANPCController* NPC = Cast<ANPCController>(GetController());
				NPC->SetNPCType(ENPCType::RunAway);
			}
		}
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

void ANPCCharacter::PlayTalkMotion()
{
	if (TalkAnimMontage)
	{
		AnimInstance->Montage_Play(TalkAnimMontage, 2.5f);
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