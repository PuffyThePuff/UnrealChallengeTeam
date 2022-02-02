// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradableCharacter.h"
#include "Kismet/GameplayStatics.h"

void AUpgradableCharacter::SetProjectileType(int newType) {
	projectileType = newType;
}

void AUpgradableCharacter::OnFire() {
	FVector scaleFactors = FVector::OneVector;
	float massMultiplier = 1.f;

	switch (projectileType) {
	case 1: scaleFactors *= 0.25f; massMultiplier *= 1.f; break;
	case 2: scaleFactors *= 8.f; massMultiplier *= 1.f; break;
	default: scaleFactors *= 1.f; massMultiplier *= 1.f;
	}

	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			if (bUsingMotionControllers)
			{
				const FRotator SpawnRotation = this->VR_MuzzleLocation->GetComponentRotation();
				const FVector SpawnLocation = this->VR_MuzzleLocation->GetComponentLocation();
				AActor* newProjectile = World->SpawnActor<AUnrealChallengeTeamProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
				newProjectile->SetActorScale3D(scaleFactors);
				newProjectile->FindComponentByClass<UStaticMeshComponent>()->GetBodyInstance()->MassScale *= massMultiplier;
				newProjectile->SetActorHiddenInGame(false);
			}
			else
			{
				const FRotator SpawnRotation = GetControlRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = ((this->FP_MuzzleLocation != nullptr) ? this->FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// spawn the projectile at the muzzle
				AActor* newProjectile = World->SpawnActor<AUnrealChallengeTeamProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
				newProjectile->SetActorScale3D(scaleFactors);
				newProjectile->FindComponentByClass<UStaticMeshComponent>()->GetBodyInstance()->MassScale *= massMultiplier;
				newProjectile->SetActorHiddenInGame(false);
			}
		}
	}

	// try and play the sound if specified
	if (this->FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = this->Mesh1P->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}