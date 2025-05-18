// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintGeneratorCommands.h"

#define LOCTEXT_NAMESPACE "FBlueprintGeneratorModule"

void FBlueprintGeneratorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "BlueprintGenerator", "Bring up BlueprintGenerator window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
