// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/Commands/Commands.h"
#include "BlueprintGeneratorStyle.h"

class FBlueprintGeneratorCommands : public TCommands<FBlueprintGeneratorCommands>
{
public:

	FBlueprintGeneratorCommands()
		: TCommands<FBlueprintGeneratorCommands>(TEXT("BlueprintGenerator"), NSLOCTEXT("Contexts", "BlueprintGenerator", "BlueprintGenerator Plugin"), NAME_None, FBlueprintGeneratorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};
