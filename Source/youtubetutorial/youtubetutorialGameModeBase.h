// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"

#include "XPCharacter.h"

#include "youtubetutorialGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class YOUTUBETUTORIAL_API AyoutubetutorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	void InitGameState() override;
	 

private:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AXPCharacter> CustomXPCharacterClass = AXPCharacter::StaticClass();
};
