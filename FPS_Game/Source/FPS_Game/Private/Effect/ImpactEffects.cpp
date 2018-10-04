// Fill out your copyright notice in the Description page of Project Settings.

#include "ImpactEffects.h"
#include "FPS_Game.h"

AImpactEffects::AImpactEffects(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bAutoDestroyWhenFinished = true;
}


void AImpactEffects::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UPhysicalMaterial* HitPhysMat = SurfaceHit.PhysMaterial.Get();
	EPhysicalSurface HitSurfaceType = UPhysicalMaterial::DetermineSurfaceType(HitPhysMat);

	// show particles
	UParticleSystem* ImpactFX = GetImpactFX(HitSurfaceType);
	if (ImpactFX)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactFX, GetActorLocation(), GetActorRotation());
	}

	// play sound
	USoundCue* ImpactSound = GetImpactSound(HitSurfaceType);
	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}

	if (DefaultDecal.DecalMaterial)
	{
		FRotator RandomDecalRotation = SurfaceHit.ImpactNormal.Rotation();
		RandomDecalRotation.Roll = FMath::FRandRange(-180.0f, 180.0f);

		UGameplayStatics::SpawnDecalAttached(DefaultDecal.DecalMaterial, FVector(1.0f, DefaultDecal.DecalSize, DefaultDecal.DecalSize),
			SurfaceHit.Component.Get(), SurfaceHit.BoneName,
			SurfaceHit.ImpactPoint, RandomDecalRotation, EAttachLocation::KeepWorldPosition,
			DefaultDecal.LifeSpan);
	}
}

UParticleSystem* AImpactEffects::GetImpactFX(TEnumAsByte<EPhysicalSurface> SurfaceType) const
{
	UParticleSystem* ImpactFX = NULL;

	switch (SurfaceType)
	{
	case FPS_Game_SURFACE_Concrete:	ImpactFX = ConcreteFX; break;
	case FPS_Game_SURFACE_Dirt:		ImpactFX = DirtFX; break;
	case FPS_Game_SURFACE_Metal:	ImpactFX = MetalFX; break;
	case FPS_Game_SURFACE_Water:	ImpactFX = WaterFX; break;
	case FPS_Game_SURFACE_Wood:		ImpactFX = WoodFX; break;
	case FPS_Game_SURFACE_Grass:	ImpactFX = GrassFX; break;
	case FPS_Game_SURFACE_Glass:	ImpactFX = GlassFX; break;
	case FPS_Game_SURFACE_Flesh:	ImpactFX = FleshFX; break;
	default:						ImpactFX = DefaultFX; break;
	}

	return ImpactFX;
}

USoundCue* AImpactEffects::GetImpactSound(TEnumAsByte<EPhysicalSurface> SurfaceType) const
{
	USoundCue* ImpactSound = NULL;

	switch (SurfaceType)
	{
	case FPS_Game_SURFACE_Concrete:	ImpactSound = ConcreteSound; break;
	case FPS_Game_SURFACE_Dirt:		ImpactSound = DirtSound; break;
	case FPS_Game_SURFACE_Water:	ImpactSound = WaterSound; break;
	case FPS_Game_SURFACE_Metal:	ImpactSound = MetalSound; break;
	case FPS_Game_SURFACE_Wood:		ImpactSound = WoodSound; break;
	case FPS_Game_SURFACE_Grass:	ImpactSound = GrassSound; break;
	case FPS_Game_SURFACE_Glass:	ImpactSound = GlassSound; break;
	case FPS_Game_SURFACE_Flesh:	ImpactSound = FleshSound; break;
	default:						ImpactSound = DefaultSound; break;
	}

	return ImpactSound;
}
