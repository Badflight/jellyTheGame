// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JellyGameProject : ModuleRules
{
	public JellyGameProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
