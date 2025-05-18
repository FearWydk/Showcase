#include "BlueprintGeneratorModule.h"
#include "Modules/ModuleManager.h"
#include "ISettingsModule.h"
#include "Widgets/Docking/SDockTab.h"
#include "BlueprintGraph/Private/BlueprintNodeSpawner.h"
#include "BlueprintNodeHelpers.h"

class FBlueprintGeneratorModule : public IModuleInterface
{
public:
void FBlueprintGeneratorModule::StartupModule() override
{
	UE_LOG(LogTemp, Warning, TEXT("Vlueprint Generator Plugin Loaded!"));

	SetupAiConnection();
}

void FBlueprintGeneratorModule::ShutdownModule() override
{
	UE_LOG(LogTemp, Warning, TEXT("Blueprint Generator Plugin Unloaded"));
}

private:

void FBlueprintGeneratorModule::SetupAiConnection()
{
	FString APIKey = TEXT("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");
	FString RequestURL = TEXT("https://api.openai.com/v1/completions");

	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetURL(RequestURL);
	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	HttpRequest->SetHeader(TEXT("Authorization"), FString("Bearer ") + APIKey);

	FString RequestBody = TEXT("{ \"model\": \"gpt-4\", \"prompt\": \"Create a player movement system in Blueprint\", \"max_tokens\": 150 }")
		HttpRequest->SetContentAsString(RequestBody);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &FBlueprintGeneratorModule::OnAPIResponse);
	HttpRequest->ProcessRequest();


}

void FBlueprintGeneratorModule::GenerateBlueprintFromAiResponse(const FString& AIResponse)
{
	if (AIResponse.Contains(TEXT("Create a node to move")))
	{
		// Assuming the AI told you to create a movement node
		UBlueprint* NewBlueprint = CreateNewBlueprint();  // You will have this method to create new Blueprints.
		UEdGraph* Graph = NewBlueprint->UbergraphPages[0];


	UEdGraphNode* MoveNode = CreateMoveNode(Graph);
	Graph->Nodes.Add(MoveNode);
	SetupMoveNodeInputs(MoveNode);
}

	else
	{
	}

void FBlueprintGeneratorModule::OnAPIResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response.IsValid())
	{
		FString AIResponse = Response->GetContentAsString();
		GenerateBlueprintFromAiResponse(AIResponse);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("API Request Failed"));
	}
}

UEdGraphNode* FBlueprintGeneratorModule::CreateMoveNode(UEdGraph* Graph)
{
	UEdGraphNode* MoveNode = NewObject<UEdGraphNode>(Graph, UEdGraphNode::StaticClass());
	MoveNode->CreateNewNode();

	MoveNode->NodePosX = 100;
	MoveNode->NodePosY = 200;

	return MoveNode;
}
};
IMPLEMENT_MODULE(FBlueprintGeneratorModule, BlueprintGenerator);