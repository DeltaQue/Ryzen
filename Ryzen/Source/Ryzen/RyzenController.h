// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interactable.h"
#include "InventoryItem.h"
#include "RyzenController.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API ARyzenController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ARyzenController();

	//�������Ʈ ������ ȣ���� �Լ�, BlueprintImplementableEvent
	//�κ��丮 ������ ��ȿ������ �Ǵ��ؾ��ϴµ� �ڵ� ������ �ǽð� ������ ��ȿ���� �Ǵ��ϱ� ����� �������Ʈ�� ��
	UFUNCTION(BlueprintImplementableEvent)
		void ReloadInventory();

	UFUNCTION(BlueprintCallable, Category = "Utils")
		int32 GetInventoryWeight();

	UFUNCTION(BlueprintCallable, Category = "Utils")
		bool AddItemToInventoryByID(FName ID);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class AInteractable* CurrentInteractable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FInventoryItem> Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 Money;

	//���� ���� �Ѱ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 InventorySlotLimit;

	//���� ���� �Ѱ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 InventoryWeightLimit;

	////////////////////////////////////////////////



protected:
	void Interact();

	virtual void SetupInputComponent() override;
};
