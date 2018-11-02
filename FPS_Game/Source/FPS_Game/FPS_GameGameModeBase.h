// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS_GameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FPS_GAME_API AFPS_GameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	
private:
	UPROPERTY()
		FTransform PlayerSpawnTransform;

	const FString JsonFilePath = FPaths::ProjectContentDir() + "/Data/LoadData.json";
	const FString QuestFilePath = FPaths::ProjectContentDir() + "/Data/QuestScript.json";
	const FString QuestDataFilePath = FPaths::ProjectContentDir() + "/Data/QuestData.json";
	const FString HealFilePath = FPaths::ProjectContentDir() + "/Data/HealNPCData.json";
	const FString AmmoFilePath = FPaths::ProjectContentDir() + "/Data/AmmoNPCData.json";

	int32 QuestScriptNum;
	int32 QuestNum;

	//NPCNum
	//0 : Heal NPC
	//1 : Ammo NPC
	int32 NPCScriptNum;
	int32 NPCNum;

	int32 QuestScriptLength;

	int32 Tutorial_Quest_Script_Max;
	int32 Stage1_Quest_Script_Max;
	int32 Stage2_Quest_Script_Max;
	int32 Heal_Script_Max;
	int32 Ammo_Script_Max;


	void SetZombieSpawnPoint();


	TArray<class AZombieCharacter*> StoreSpawnZombie;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "EnemySpawnData")
		TArray<TSubclassOf<class AZombieCharacter> > SpawnZombieArray;

	UPROPERTY(EditDefaultsOnly, Category = "EnemySpawnData")
		TArray<TSubclassOf<class AZombieCharacter> > Stage2SpawnZombieArray;

	/*UPROPERTY(EditDefaultsOnly, Category = "EnemySpawnData")
		TArray<TSubclassOf<AActor> > Stage1_Spawnpoint;*/

	TArray<FVector> ZombieSpawnPoint;
	

public:
	void SetPlayerSpawnTransform(FTransform SpawnTransform);

	FTransform GetPlayerSpawnTransform() const;

	float DamageCalc(float Damage, AActor* DamagedActor, struct FDamageEvent const &DamageEvent, AController* EventInstigator, AActor* DamageCauser) const;

	bool SetCheckPoint(const FVector Location);

	FVector GetCheckPoint();

	//����Ʈ ��ȭ������ �о����
	UFUNCTION(BlueprintCallable, Category = "TextScript")
		FText GetQuestScript();
	UFUNCTION(BlueprintCallable, Category = "TextScript")
		FText GetNPCScript(int32 NPCType);

	//����Ʈ ���� �����͸� �о����
	//DataNum
	//0 : ����Ʈ �̸�
	//1 : ����Ʈ ����
	//2 : ����Ʈ ��ǥ
	UFUNCTION(BlueprintCallable, Category = "TextScript")
		FText GetQuestData(int DataNum);

	UFUNCTION(BlueprintImplementableEvent, Category = "GamePause")
		void SetGamePause();
	UFUNCTION(BlueprintImplementableEvent, Category = "GamePause")
		void SetGameUnPause();

	void NextQuestScript();
	void NextQuest();
	void ClearQuest();
	
	void NextNPCScript(int32 NPCNum);
	void ClearNPCScript();

	int32 GetQuestScriptNum() const;
	int32 GetQuestNum() const;
	int32 GetQuestScriptMaxSize(int32 QuestNum) const;



	int32 GetNPCScriptNum() const;
	int32 GetNPCScriptMaxSize(int NPCType) const;

	void SpawnZombie();

	TArray<class AZombieCharacter*> GetSpawnZombie();

	//0 : Tutorial
	//1 : Stage1 Quest
	//2 : Stage2 Quest
	bool Complete_Quest[3] = { false, false, false };

	void SetCompleteQuest(int32 QuestNum);
};
