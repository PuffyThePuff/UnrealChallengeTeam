// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealChallengeTeamCharacter.h"
#include "UpgradableCharacter.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHALLENGETEAM_API AUpgradableCharacter : public AUnrealChallengeTeamCharacter
{
	GENERATED_BODY()

protected:
	int projectileType = 0;

public:
	void SetProjectileType(int newType);
};