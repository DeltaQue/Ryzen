// Fill out your copyright notice in the Description page of Project Settings.

#include "RyzenBaseCharacter.h"


// Sets default values
ARyzenBaseCharacter::ARyzenBaseCharacter(const class FObjectInitializer& ObjectInitializer)
{

	NoiseEmitterComp = CreateDefaultSubobject<UPawnNoiseEmitterComponent>(TEXT("NoiseEmitterComp"));
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

float ARyzenBaseCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (Health <= 0.0f) 
	{
		return -1.0f;
	}

	//��ӹ��� �ڽ� Ŭ�������� TakeDamage�� ���ڸ� �Ѱܹ޾� Pawn Class�� TakeDamage�� ������ �����
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	if (ActualDamage > 0.0f)
	{
		Health -= ActualDamage;
		if (Health <= 0.0f)
		{
			
		}
	}

	return ActualDamage;
}

bool ARyzenBaseCharacter::CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const
{
	if (bisDying || IsPendingKill() || GetWorld()->GetAuthGameMode() == nullptr)
	{
		return true;
	}

	return true;
}

bool ARyzenBaseCharacter::Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser)
{
	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = 0.0f;



	return true;
}

void ARyzenBaseCharacter::OnDeath(float KillingDamage, FDamageEvent const& DamageEvent, APawn* PawnInstigator, AActor* DamageCauser)
{
	if (bisDying)
	{
		return;
	}

}