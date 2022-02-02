// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealChallengeTeam : ModuleRules
{
	public UnrealChallengeTeam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" ,"ApexDestruction"});
	}
}
