// Fill out your copyright notice in the Description page of Project Settings.

#include "RyzenController.h"
#include "RyzenStateBase.h"
#include "RyzenCharacter.h"



ARyzenController::ARyzenController()
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

int32 ARyzenController::GetInventoryWeight()
{
	int32 Weight = 0;
	for (auto& Item : Inventory)
	{
		Weight += Item.Weight;
	}

	return Weight;
}

bool ARyzenController::AddItemToInventoryByID(FName ID)
{
	ARyzenStateBase* GameState = Cast<ARyzenStateBase>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		//�κ��丮 ���� 50������ �����丮 ������ ���� ����, �κ��丮 Limit���Ժ��� ������ ���Ը� �� ������ �κ��丮 ���԰� Limit���� ����� ������ ���� ���� 
		if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			Inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}

void ARyzenController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//FŰ�� ������ Interact() ȣ��
	InputComponent->BindAction("Interact", IE_Pressed, this, &ARyzenController::Interact);
}

void ARyzenController::Interact()
{
	//Ryzen Character���� Collection Sphere�� üũ�� ���Ͱ� ��ȿ�ϸ� Interactable_Implement�Լ��� ȣ����.
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}


