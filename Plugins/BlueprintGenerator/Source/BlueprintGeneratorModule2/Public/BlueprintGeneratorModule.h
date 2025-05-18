#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class FBlueprintGeneratorModule : public FDefaultModuleImpl
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	void SetupAiConnection();
	void GenerateBlueprintFromAiResponse(const FString& AIResponse);
};
