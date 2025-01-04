// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "MoveComponent.generated.h"

UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentReachEndPointSignature,bool, IsTopEndPoint);

UCLASS( ClassGroup=(youtubetutorial), meta=(BlueprintSpawnableComponent) )
class YOUTUBETUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

private:
	friend class FMoveComponentVisualizer;

	//Offset to move
	UPROPERTY(EditAnywhere)
	FVector MoveOffSet;

	//Speed 
	UPROPERTY(EditAnywhere)
	float Speed = 1.f;

	//Enable the movement of the component
	UPROPERTY(EditAnywhere)
	bool MoveEnable = true;

	//On Extreme reached event
	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndPointReached;

	//Computed locations
	FVector StartRelativeLocation;
	FVector MoveOffsetNorm;

	float MaxDistance = 0.0f;
	float CurrentDistance = 0.0f;
	int MoveDirection = 1;
public:	
	// Sets default values for this component's properties
	UMoveComponent();

	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove);

	UFUNCTION(BlueprintCallable)
	void ResetMovement();

	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
