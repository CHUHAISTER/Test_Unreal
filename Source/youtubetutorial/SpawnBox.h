// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"

#include "SpawnBox.generated.h"

UCLASS()
class YOUTUBETUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Called when the actor stops playing	 
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	//Will spawn an actor of the setted class now
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	//Actor class to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	//Avarage time between spawns (without random) 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.f;

	//Random +/- offset of the spawn time
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RandomSpawnTimeOffset = 1.f;

	//Change if actors spawned
	UFUNCTION(BlueprintCallable)
	void EnableActorSpawning(bool Enable);

private:
	UFUNCTION()
	void SpawnActorScheduled();

	//Will schedule an actor spawn 
	void ScheduleActorSpawn();

	//Box in which we will spawn the actors	 
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	//Indicate that the actor should spawn actors
	UPROPERTY(EditAnywhere)
	bool ShouldSpawn = false;

	//helper for timing
	FTimerHandle SpawnTimerHandle;
};
