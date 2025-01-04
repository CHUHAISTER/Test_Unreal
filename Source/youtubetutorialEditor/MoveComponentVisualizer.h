// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentVisualizer.h"
#include "youtubetutorial/MoveComponent.h"

/**
 * 
 */
class YOUTUBETUTORIALEDITOR_API FMoveComponentVisualizer : public FComponentVisualizer
{
public:
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;

};
