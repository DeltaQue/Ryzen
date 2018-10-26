// Fill out your copyright notice in the Description page of Project Settings.

#include "RPlayerController.h"
#include "FPS_Game.h"
#include "CameraManager.h"
#include "GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

//wWidgetArray
//1 : QuestScriptWidget
//2 : HealWidget
//3 : AmmoWidget

ARPlayerController::ARPlayerController(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PlayerCameraManagerClass = ACameraManager::StaticClass();

	
	bTurnViewTarget = false;

	TalkNPCType = -1;
}

void ARPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ARPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("Guide", IE_Pressed, this, &ARPlayerController::OpenAllGuideWidget);
	//InputComponent->BindAction("Guide", IE_Released, this, &ARPlayerController::CloseGuideWidget);

	InputComponent->BindAction("Anykey", IE_Released, this, &ARPlayerController::NextScript);

	//InputComponent->BindAction("ESC", IE_Released, this, &ARPlayerController::CloseAllWidget);
}


void ARPlayerController::OnScreenMessage(FName string)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, string.ToString());
}

void ARPlayerController::OnScreenMessage(FString string)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, *string);
}

void ARPlayerController::OnScreenMessageAmmo(int32 ammo)
{
	//UE_LOG(LogClass, Log, TEXT("Remaining Ammo : %d", ammo));

	FString str = FString::Printf(TEXT("Remaining Ammo : %d"), ammo);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, str);
}

void ARPlayerController::OnScreenMessageSwitch(int32 val)
{
	switch (val)
	{
	case 0:
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Attach Success"));
		break;

	case 1:
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Attach Fail"));
		break;

	default:
		break;
	}
}

void ARPlayerController::OpenAllGuideWidget()
{
	if (GetWorld())
	{
		if (wGuideWidgetArray.Num() != 0)
		{
			//Movement Guide Widget
			if (wGuideWidgetArray[0])
			{
				MovementGuideWidget = CreateWidget<UUserWidget>(this, wGuideWidgetArray[0]);

				if (MovementGuideWidget)
				{
					MovementGuideWidget->AddToViewport();
				}

			}
			//Weapon Guide Widget
			if (wGuideWidgetArray[1])
			{
				WeaponGuideWidget = CreateWidget<UUserWidget>(this, wGuideWidgetArray[1]);

				if (WeaponGuideWidget)
				{
					WeaponGuideWidget->AddToViewport();
				}
			}

			bShowMouseCursor = true;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->SetGamePause();
		}
	}
}

void ARPlayerController::OpenGuideWidget(int GuideWidgetNum)
{
	if (GetWorld())
	{
		if (wGuideWidgetArray.Num() != 0)
		{
			switch (GuideWidgetNum)
			{
			case 0:
				//Movement Guide Widget
				if (wGuideWidgetArray[0])
				{
					MovementGuideWidget = CreateWidget<UUserWidget>(this, wGuideWidgetArray[0]);

					if (MovementGuideWidget)
					{
						MovementGuideWidget->AddToViewport();
					}
				}
				break;

			case 1:
				//Weapon Guide Widget
				if (wGuideWidgetArray[1])
				{
					WeaponGuideWidget = CreateWidget<UUserWidget>(this, wGuideWidgetArray[1]);

					if (WeaponGuideWidget)
					{
						WeaponGuideWidget->AddToViewport();
					}
				}
				break;

			default:
				break;
			}

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->SetGamePause();
		}
	}
}

void ARPlayerController::CloseGuideWidget(int GuideWidgetNum)
{
	switch (GuideWidgetNum)
	{
	case 0:
		if (MovementGuideWidget)
		{
			MovementGuideWidget->RemoveFromParent();
			MovementGuideWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->SetGameUnPause();
		}
		break;

	case 1:
		if (WeaponGuideWidget)
		{
			WeaponGuideWidget->RemoveFromParent();
			WeaponGuideWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->SetGameUnPause();
		}
		break;

	default:
		break;
	}
	
}

void ARPlayerController::OpenWidget(int32 WidgetNum)
{
	if (wWidgetArray.Num() != 0)
	{
		//Widget Num
		//1 : QuestScript WIdget
		//2 : Heal Widget
		//3 : Ammo Widget
		switch (WidgetNum)
		{
		case 0:
		case 1:

			if (wWidgetArray[1]) // Check if the Asset is assigned in the blueprint.
			{
				// Create the widget and store it.
				QuestScriptWidget = CreateWidget<UUserWidget>(this, wWidgetArray[1]);

				// now you can use the widget directly since you have a referance for it.
				// Extra check to  make sure the pointer holds the widget.
				if (QuestScriptWidget)
				{
					//let add it to the view port
					QuestScriptWidget->AddToViewport();
				}

			}
			break;

			//Health ȸ�� NPC Sciprt ����
		case 2:
			if (wWidgetArray[2])
			{
				HealWidget = CreateWidget<UUserWidget>(this, wWidgetArray[3]);

				if (HealWidget)
				{
					HealWidget->AddToViewport();
				}
			}
			break;

			//Ammo ���� NPC Sciprt ����
		case 3:
			if (wWidgetArray[3])
			{
				AmmoWidget = CreateWidget<UUserWidget>(this, wWidgetArray[3]);

				if (AmmoWidget)
				{
					AmmoWidget->AddToViewport();
				}
			}
			break;
		default:
			break;
		}
	}
}

void ARPlayerController::CloseWidget(int32 WidgetNum)
{
	//Widget Num
	//1 : Tutorial WIdget
	//2 : Heal Widget
	//3 : Ammo Widget

	switch (WidgetNum)
	{
	case 0:
	case 1:
		if (QuestScriptWidget)
		{
			QuestScriptWidget->RemoveFromParent();
			QuestScriptWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

			//���� ����Ʈ�� �Ѿ���Ҷ�
			if (GameMode->GetQuestScriptMaxSize(GameMode->GetQuestNum()) - 1 == GameMode->GetQuestScriptNum())
			{
				//���� ����Ʈ�� �Ѿ�� ���� => GameMode���� SetCompleteQuest()���� ����
				//if (GameMode->Complete_Quest[GameMode->GetQuestNum()] == true)
					//GameMode->NextQuest();
			}
			//��ũ��Ʈ�� ������ ������� �ʾҴµ� ����Ʈ ������ �����Ҷ�
			else if(GameMode->GetQuestScriptMaxSize(GameMode->GetQuestNum()) - 1 > GameMode->GetQuestScriptNum())
			{
				GameMode->ClearQuest();
			}
		}
		break;

	case 2:
		if (HealWidget)
		{
			HealWidget->RemoveFromParent();
			HealWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->ClearQuest();
		}
		break;

	case 3:
		if (AmmoWidget)
		{
			AmmoWidget->RemoveFromParent();
			AmmoWidget = nullptr;

			AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
			GameMode->ClearQuest();
		}
		break;

	default:
		break;
	}
	
}

void ARPlayerController::OpenStatusHUD()
{
	if (wStatusHUD) 
	{
		StatusHUD = CreateWidget<UUserWidget>(this, wStatusHUD);

		if (StatusHUD)
		{
			StatusHUD->AddToViewport();
		}

	}
}

void ARPlayerController::CloseStatusHUD()
{
	if (StatusHUD)
	{
		StatusHUD->RemoveFromParent();
		StatusHUD = nullptr;
	}
}

UUserWidget* ARPlayerController::GetStatusHUD() const
{
	if (StatusHUD)
		return StatusHUD;
	else
		return nullptr;
}


void ARPlayerController::NextScript()
{
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	APlayerCharacter* Player = Cast<APlayerCharacter>(GetPawn());

	switch (TalkNPCType)
	{
	//case 0 : Quest NPC
	case 0:
		switch (GameMode->GetQuestNum())
		{
			//���� ��ũ��Ʈ�� ���ΰ��

			//Tutorial Quest
		case 0:
			if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(0) - 1)
			{
				//��ȭâ ����
				CloseWidget(0);

				//����Ʈ UI Ȱ��ȭ
				Player->SetCurrentQuestActivate(0);
			}
			//Ʃ�丮�� �̺�Ʈ
			else if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(0) - 2)
			{
				bTurnViewTarget = true;
				//Ʃ�丮�� ���� ����
				GameMode->SpawnZombie();
			}
			break;

			//Stage1 - Quest 
		case 1:
			if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(1) - 1)
			{
				CloseWidget(1);

				//����Ʈ UI Ȱ��ȭ
				Player->SetCurrentQuestActivate(1);

				GameMode->SpawnZombie();
			}
			break;

			//Stage2 - Quest
		case 2:
			if (GameMode->GetQuestScriptNum() == GameMode->GetQuestScriptMaxSize(2) - 1)
			{
				CloseWidget(2);

				//����Ʈ UI Ȱ��ȭ
				Player->SetCurrentQuestActivate(2);

				GameMode->SpawnZombie();
			}
			break;

		default:
			break;
		}

		//���� ��ũ��Ʈ�� �ִ°��
		/*if (QuestWidget)
		{
		GameMode->NextQuestScript();
		}*/
		if (GameMode->GetQuestNum() < 3)
		{
			GameMode->NextQuestScript();
		}
		
		break;

	//case 1 : Heal NPC
	case 1:
		if (GameMode->GetNPCScriptNum() == GameMode->GetNPCScriptMaxSize(1) - 1)
		{
			CloseWidget(2);

			//HP ȸ�� �Լ�
		}
		break;

	//case 2 : Ammo NPC
	case 2:
		if (GameMode->GetNPCScriptNum() == GameMode->GetNPCScriptMaxSize(2) - 1)
		{
			CloseWidget(3);

			//Ammo ���� �Լ�
		}

		break;

	default:
		break;
	}
	
	
	
}

int32 ARPlayerController::BindKilledpoint()
{
	return Killpoint;
}

int32 ARPlayerController::GetScoreKillpoint() const
{
	return Killpoint;
}

void ARPlayerController::SetScoreKillpoint()
{
	Killpoint++;
}

void ARPlayerController::SetTalkNPCType(int32 NPCType)
{
	TalkNPCType = NPCType;
}


void ARPlayerController::CloseAllWidget()
{
	if (MovementGuideWidget)
	{
		MovementGuideWidget->RemoveFromParent();
		MovementGuideWidget = nullptr;
	}
	if (WeaponGuideWidget)
	{
		WeaponGuideWidget->RemoveFromParent();
		WeaponGuideWidget = nullptr;
	}
	if (QuestScriptWidget)
	{
		QuestScriptWidget->RemoveFromParent();
		QuestScriptWidget = nullptr;
	}
	if (HealWidget)
	{
		HealWidget->RemoveFromParent();
		HealWidget = nullptr;
	}
	if (AmmoWidget)
	{
		AmmoWidget->RemoveFromParent();
		AmmoWidget = nullptr;
	}

	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());
	GameMode->ClearNPCScript();
	GameMode->ClearQuest();
}


void ARPlayerController::SetGamePause()
{
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

	GameMode->SetGamePause();
}


void ARPlayerController::SetGameUnPause()
{
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

	GameMode->SetGameUnPause();
}

int32 ARPlayerController::GetQuestScore() const
{
	AFPS_GameGameModeBase* GameMode = Cast<AFPS_GameGameModeBase>(GetWorld()->GetAuthGameMode());

	if (GameMode->GetQuestNum() == 0)
	{
		return GetScoreKillpoint();
	}
	else if (GameMode->GetQuestNum() == 1)
	{
		return GetScoreKillpoint() - 1;
	}
	else
		return -1;
}