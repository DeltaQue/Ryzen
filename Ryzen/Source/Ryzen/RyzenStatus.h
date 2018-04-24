// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RyzenStatus.generated.h"

/**
 * 
 */
UCLASS()
class RYZEN_API URyzenStatus : public UObject
{
	GENERATED_BODY()
	
	
	/* ĳ���� �������ͽ� */
	//��, ��ø, ü��, ���ɳ���, ���ݷ�, ���ݼӵ�, ü��, ���� ��ġ, ����ġ

	//���ݷ� = �� * 2, 1�ܰ� ������ ü�� : 100, 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Strength;; //��, ���ݷ� ��� �⺻ Status : 10

	//���ݼӵ� = ��ø * 0.5, �⺻ ���ݼӵ� : 0.5/s, 2�ʴ� 1�� ����ӵ�
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Agility; //��ø, ���ݼӵ� ���  �⺻ Status : 10

	//ü�� = Stamina * 10  if)Stamina : 15, ü�� : 150
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Stamina; //ü��, ü�� ���  �⺻ Status : 10 

	/*���� ����, ���� ��ġ�� 100�� �Ѿ�� ü���� 2�ʿ� �ѹ��� ü�� ����
		���� ü�� ���� ��ġ/2s = 20 % ���� ����  */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Status", meta = (AllowPrivateAccess = "true"))
		int32 Radiation; //���� ����, ���� ���⿡ ���� ���ҵǴ� ü�� ���� ,�⺻ Status : 5

	
public:
	int32 GetStr() const { return Strength; }
	int32 GetAgr() const { return Agility; }
	int32 GetStm() const { return Stamina; }
	int32 GetRdt() const { return Radiation; }
};
