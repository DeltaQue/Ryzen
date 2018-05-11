// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Player/RyzenBaseCharacter.h"
#include "Interactable.h"
#include "Bullet.h"
#include "PlayerCharacter.generated.h"


UCLASS(config = Game)
class APlayerCharacter : public ARyzenBaseCharacter
{
	GENERATED_BODY()

private:
	//  meta = (AllowPrivateAccess = "true")�� ������ ���� ����
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	//������ ���� �ݰ�üũ ��ü
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CollectionSphere;


	/* Bullet�� �߻�Ǵ� ��ġ */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* MuzzleLocation;

	//Bullet�� �߻�� �뷫�� ��ġ
	FVector GunOffset;
	FVector CameraOffset;

	float LastNoiseLoudness;

	float LastMakeNoiseTime;

	//Fire Function
	void OnFire();


public:
	APlayerCharacter(const class FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaTime) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool JumpButtonDown;

	UFUNCTION(BlueprintCallable, Category = "AI")
		void MakePawnNoise(float Loudness);

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);


	/** Collection Sphere ���� ���� AutoPickup ������ ��ü�� �ִٸ� ����  */
	void CollectAutoPickups();


	/** Collection Sphere ���� �� ĳ���� �þ�(���콺������)�� ��ȣ�ۿ� ������ ��ü�� �ִ��� �Ǵ� */
	void CheckForInteractables();


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	virtual void BeginPlay();
public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	//Pickup��û �Լ�
	//void CheckForManualPickup(AInteractable *Things);

	//Fire Animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		class UAnimMontage* FireAnimation;

	UPROPERTY(VisibleDefaultsOnly)
		class UAnimInstance* AnimInstance;

	//Gun Fire Sound
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	//Gun Fire Particles Effect
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UParticleSystem* ParticleFX;

	UPROPERTY(VisibleDefaultsOnly)
		class UParticleSystemComponent* FireParticle;

	/* Character Mesh */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* CharacterMesh;

	/* Bullet Class */
	UPROPERTY(EditDefaultsOnly, Category = Bullet)
		TSubclassOf<ABullet> Bullets;
};
