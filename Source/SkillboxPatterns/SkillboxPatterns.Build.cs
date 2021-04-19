// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SkillboxPatterns : ModuleRules
{
	public SkillboxPatterns(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
