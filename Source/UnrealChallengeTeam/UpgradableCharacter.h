// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealChallengeTeamCharacter.h"
#include"UnrealChallengeTeamProjectile.h"
#include "UpgradableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHALLENGETEAM_API AUpgradableCharacter : public AUnrealChallengeTeamCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere) int projectileType = 0;

	virtual void OnFire() override;

public:
	UFUNCTION(BlueprintCallable) void SetProjectileType(int newType);
};