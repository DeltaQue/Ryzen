// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "FPS_Game.h"
#include "BaseCharacter.h"




APlayerCharacter::APlayerCharacter(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetupAttachment(RootComponent);
	GetMesh()->bOnlyOwnerSee = true;
	GetMesh()->bOwnerNoSee = false;
	GetMesh()->bCastDynamicShadow = false;
	GetMesh()->bReceivesDecals = false;
	GetMesh()->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::OnlyTickPoseWhenRendered;
	GetMesh()->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);


	bIsADS = false;
	bIsJumping = false;
	bIsSprint = false;

	bHasNewFocus = true;

	fDefaultSpeed = GetCharacterMovement()->MaxWalkSpeed;
	fWalkModifier = 1.f;
	fSprintModifier = 1.5f;

	WeaponAttachPoint = "WeaponPoint";
}

void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SetDefaultWeaponEquip();
}

void APlayerCharacter::OnCameraUpdate(const FVector& CameraLocation, const FRotator& CameraRotation)
{
	//USkeletalMeshComponent* DefMesh1P = Cast<USkeletalMeshComponent>(GetClass()->GetDefaultSubobjectByName(TEXT("PawnMesh1P")));
	const FMatrix DefMeshLS = FRotationTranslationMatrix(GetMesh()->RelativeRotation, GetMesh()->RelativeLocation);
	const FMatrix LocalToWorld = ActorToWorld().ToMatrixWithScale();

	const FRotator RotCameraPitch(CameraRotation.Pitch, 0.0f, 0.0f);
	const FRotator RotCameraYaw(0.0f, CameraRotation.Yaw, 0.0f);

	const FMatrix LeveledCameraLS = FRotationTranslationMatrix(RotCameraYaw, CameraLocation) * LocalToWorld.Inverse();
	const FMatrix PitchedCameraLS = FRotationMatrix(RotCameraPitch) * LeveledCameraLS;
	const FMatrix MeshRelativeToCamera = DefMeshLS * LeveledCameraLS.Inverse();
	const FMatrix PitchedMesh = MeshRelativeToCamera * PitchedCameraLS;

	//GetMesh()->SetRelativeLocationAndRotation(PitchedMesh.GetOrigin(), PitchedMesh.Rotator());
}

void APlayerCharacter::AddWeapon(AWeapons* TargetWeapon)
{
	if (TargetWeapon)
	{
		TargetWeapon->OnEnterInventory(this);
		Inventory.AddUnique(TargetWeapon);
	}
}

void APlayerCharacter::RemoveWeapon(AWeapons* TargetWeapon)
{

}

void APlayerCharacter::SetDefaultWeaponEquip()
{
	if (DefaultWeapon.Num() > 0)
	{
		int32 NumWeaponClasses = DefaultWeapon.Num();
		for (int32 i = 0; i < NumWeaponClasses; i++)
		{
			if (DefaultWeapon[i])
			{
				FActorSpawnParameters SpawnInfo;
				SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				AWeapons* NewWeapon = GetWorld()->SpawnActor<AWeapons>(DefaultWeapon[i], SpawnInfo);
				AddWeapon(NewWeapon);

				ARPlayerController* Cont = Cast<ARPlayerController>(GetController());
				Cont->OnScreenMessageSwitch(0);
			}
		}

		if (Inventory.Num() > 0)
		{
			EquipWeapon(Inventory[0]);
		}
	}
}


void APlayerCharacter::EquipWeapon(AWeapons* NewWeapon)
{
	SetCurrentWeapon(NewWeapon, CurrentWeapon);
}


void APlayerCharacter::SetCurrentWeapon(AWeapons* NewWeapon, AWeapons* LastWeapon)
{
	AWeapons* LocalLastWeapon = NULL;

	if (LastWeapon != NULL)
	{
		LocalLastWeapon = LastWeapon;
	}
	else if (NewWeapon != CurrentWeapon)
	{
		LocalLastWeapon = CurrentWeapon;
	}

	// ���� ����UnEquip
	if (LocalLastWeapon)
	{
		LocalLastWeapon->OnUnEquip();
	}

	CurrentWeapon = NewWeapon;

	// NewWeapon Equip
	if (NewWeapon)
	{
		NewWeapon->SetOwnerWeapon(this);

		NewWeapon->OnEquip(LastWeapon);
	}
}


void APlayerCharacter::StartWeaponFire()
{
	if (!bIsFire)
	{
		bIsFire = true;
		
		if (CurrentWeapon) 
		{
			CurrentWeapon->StartFire();
		}
	}
}


void APlayerCharacter::StopWeaponFire()
{
	if (bIsFire)
	{
		bIsFire = false;
		
		if(CurrentWeapon)
			CurrentWeapon->StopFire();
	}
}


class AWeapons* APlayerCharacter::GetWeapon() const
{
	return CurrentWeapon;
}

bool APlayerCharacter::CanFire() const
{
	return IsAlive();
}

FName APlayerCharacter::GetWeaponAttachPoint() const
{
	return WeaponAttachPoint;
}

USkeletalMeshComponent* APlayerCharacter::GetOwenerMesh() const
{
	return GetMesh();
}

void APlayerCharacter::CheckForWeaponInView(FVector CameraLocation, FVector CameraFowardVector, FRotator CameraRotator)
{
	// LineTrace�� ��Ʈ�Ǵ� ���� üũ
	FHitResult HitResult;

	int32 Range = 500;
	FVector StartTrace = CameraLocation;
	FVector EndTrace = (CameraFowardVector * Range) + StartTrace;

	//ĳ���� ��ü�� LineTrace�� Ignore�ؼ� LineTrace�� Hit�����ʰ� ��
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	// ECC_Visibility�� �𸮾� ������Ʈ �Ǵ� ����, Visible�� �Ǿ��ִ� ��� ���͸� ������� Check ??
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, QueryParams))
	{
		AWeapons* Pickup = Cast<AWeapons>(HitResult.GetActor());

		if (Pickup)
		{
			Pickup->OnBeginFocus();
			PickupWeapon = Pickup;
		}

	}
	//Hit�� Actor�� ���ٸ� nullptr�� 
	PickupWeapon->OnEndFocus();
}


void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::OnStartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::OnStopJump);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::OnStartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::OnStopFire);
	PlayerInputComponent->BindAction("ADS", IE_Pressed, this, &APlayerCharacter::OnStartADS);
	PlayerInputComponent->BindAction("ADS", IE_Released, this, &APlayerCharacter::OnStopADS);
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &APlayerCharacter::OnReload);


	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::OnStartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::OnStopSprint);

	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &APlayerCharacter::WeaponEquip);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

void APlayerCharacter::Tick(float DeltaTime)
{

}

void APlayerCharacter::OnStartJump()
{
	bIsJumping = true;
	Jump();
}

void APlayerCharacter::OnStopJump()
{
	bIsJumping = false;
	StopJumping();
}

void APlayerCharacter::OnStartFire()
{
	if (bIsSprint)
	{
		OnStopSprint();
	}
	StartWeaponFire();
}

void APlayerCharacter::OnStopFire()
{
	StopWeaponFire();
}

void APlayerCharacter::OnStartADS()
{
	bIsADS = true;
}

void APlayerCharacter::OnStopADS()
{
	bIsADS = false;
}

void APlayerCharacter::OnReload()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->StartReload();
	}

}

void APlayerCharacter::OnStartSprint()
{
	bIsSprint = true;

	GetCharacterMovement()->MaxWalkSpeed = fDefaultSpeed * fSprintModifier + fWalkModifier;
}

void APlayerCharacter::OnStopSprint()
{
	bIsSprint = false;

	GetCharacterMovement()->MaxWalkSpeed = fDefaultSpeed + fWalkModifier;
}

void APlayerCharacter::WeaponEquip()
{
	if (PickupWeapon)
	{
		AddWeapon(PickupWeapon);
	}
}

void APlayerCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		//// find out which way is forward
		//const FRotator Rotation = Controller->GetControlRotation();
		//const FRotator YawRotation(0, Rotation.Yaw, 0);

		//// get forward vector
		//const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		const bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
		const FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		if (bIsADS)
		{
			float SlowVal = Value / 2.f;

			AddMovementInput(Direction, SlowVal);
		}
		else if (!bIsADS)
		{
			AddMovementInput(Direction, Value);
		}
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		//const FRotator Rotation = Controller->GetControlRotation();
		//const FRotator YawRotation(0, Rotation.Yaw, 0);

		//const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		const FQuat Rotation = GetActorQuat();
		const FVector Direction = FQuatRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		if (bIsADS)
		{
			float SlowVal = Value / 2.f;
			// add movement in that direction
			AddMovementInput(Direction, SlowVal);
		}
		else if (!bIsADS)
		{
			// add movement in that direction
			AddMovementInput(Direction, Value);
		}
	}
}

void APlayerCharacter::StopAllAnimMontages()
{
	USkeletalMeshComponent* Mesh = GetMesh();
	if (Mesh && Mesh->AnimScriptInstance)
	{
		Mesh->AnimScriptInstance->Montage_Stop(0.0f);
	}

}

bool APlayerCharacter::IsTargeting() const
{
	return bIsADS;
}

bool APlayerCharacter::IsJumping() const
{
	return bIsSprint;
}

bool APlayerCharacter::IsSprint() const
{
	return bIsSprint;
}

bool APlayerCharacter::IsFire() const
{
	return bIsFire;
}

float APlayerCharacter::GetDefaultSpeed()
{
	return fDefaultSpeed + fWalkModifier;
}

float APlayerCharacter::GetPlayerHP()
{
	return GetHealth();
}