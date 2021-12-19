// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UnrealChallengeTeamHUD.generated.h"

UCLASS()
class AUnrealChallengeTeamHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUnrealChallengeTeamHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

