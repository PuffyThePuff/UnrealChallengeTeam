// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealChallengeTeamGameMode.h"
#include "UnrealChallengeTeamHUD.h"
#include "UnrealChallengeTeamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealChallengeTeamGameMode::AUnrealChallengeTeamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealChallengeTeamHUD::StaticClass();
}
