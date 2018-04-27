// Fill out your copyright notice in the Description page of Project Settings.

#include "RyzenBaseCharacter.h"


// Sets default values
ARyzenBaseCharacter::ARyzenBaseCharacter(const class FObjectInitializer& ObjectInitializer)
{


}


bool ARyzenBaseCharacter::IsAlive() const{
	if (Health > 0)
		return true;
	else
		return false;
}

float ARyzenBaseCharacter::GetHealth() const{
	return Health;
}

float ARyzenBaseCharacter::GetMaxHealth() const{
	return 100.0f;
}


FRotator ARyzenBaseCharacter::GetAimOffsets() const{
	/*GetBaseAimRotation()��Pawn�� Ÿ�� ȸ���� �����ݴϴ�. 
	��Ʈ�ѷ����ִ� ���, �⺻������ AI�� Pawn rotation�� 
	�ΰ� �÷��̾��� ī�޶� (ũ�ν����) ȸ�� �� �÷��̾��� '�ü�'������ ��ǥ���Ѵ�.*/
	const FVector AimDirWS = GetBaseAimRotation().Vector();
	const FVector AimDirLS = ActorToWorld().InverseTransformVectorNoScale(AimDirWS);
	const FRotator AimRotLS = AimDirLS.Rotation();

	return AimRotLS;
}