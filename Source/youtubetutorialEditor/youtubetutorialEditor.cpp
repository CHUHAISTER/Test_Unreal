#include "youtubetutorialEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"


IMPLEMENT_GAME_MODULE(FyoutubetutorialEditorModule, youtubetutorialEditor);

void FyoutubetutorialEditorModule::StartupModule()
{
	//Check if editor is valid
	if (GUnrealEd)
	{
		//Registering the move visualizer
		TSharedPtr<FMoveComponentVisualizer> MoveVisualizer = MakeShareable(new FMoveComponentVisualizer);
		if (MoveVisualizer.IsValid()) 
		{
			GUnrealEd->RegisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName(), MoveVisualizer);
			MoveVisualizer->OnRegister();
		}
	}
}

void FyoutubetutorialEditorModule::ShutdownModule()
{
	//Check if editor is valid
	if (GUnrealEd)
	{
		GUnrealEd->UnregisterComponentVisualizer(UMoveComponent::StaticClass()->GetFName());
	}
}
