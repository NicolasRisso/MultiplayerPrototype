// Copyright Nicolas Risso 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interface/TriggerCounterInterface.h"
#include "PZMovingPlatform.generated.h"

/** @brief Determinate which type of movement the platform will perform. \n\n
 * Details of the movement types:
 * @li **GoForwardAndBackward**: Platform will go through all locations in array, and them go back;
 * @li **Loop**: Platform will go though all locations in array and them go to the first, in a cycle. */
UENUM(BlueprintType)
enum class EMovingPlatformType : uint8
{
	GoForwardAndBackward UMETA(DisplayName = "Go Forward And Backward"),
	Loop UMETA(DisplayName = "Loop")
};

/** A moving platform that can have its moving points, speed, and move style customized. */
UCLASS()
class PROJECTZOMBIES_API APZMovingPlatform : public AStaticMeshActor, public ITriggerCounterInterface
{
	GENERATED_BODY()

public:
	APZMovingPlatform();
	
	virtual void Tick(float DeltaSeconds) override;

	virtual void AddActiveTrigger_Implementation() override;
	virtual void RemoveActiveTrigger_Implementation() override;

	/** Functions to Call when a platform starts moving by its triggers */
	UFUNCTION(BlueprintImplementableEvent)
	void StartedMoving();

	/** Functions to Call when a platform stops moving by its triggers */
	UFUNCTION(BlueprintImplementableEvent)
	void StoppedMoving();

protected:
	virtual void BeginPlay() override;

private:
	/** Determinate if the platform will move by itself or if it needs to be powered by at least one trigger. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings|Triggers", meta = (AllowPrivateAccess = true))
	bool bNeedTriggerToMove = false;

	/** The minimum required amount of triggers so the platform can start moving. Only works if "bNeedTriggerToMove" is set to true. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Settings|Triggers", meta = (AllowPrivateAccess = true))
	int MinimumTriggersToMove = 1;
	
	/** Determinate which type of movement the platform will perform. */
	UPROPERTY(EditAnywhere, Category = "Movement Settings", meta = (AllowPrivateAccess = true))
	EMovingPlatformType MovementType = EMovingPlatformType::GoForwardAndBackward;

	/** An array that stores all the target locations that the platform will go to. */
	UPROPERTY(EditAnywhere, Category = "Movement Settings", meta = (AllowPrivateAccess = true, MakeEditWidget = true))
	TArray<FVector> TargetLocations = TArray<FVector>();

	/** The amount of centimeters that the platform will travel per second. (cm/s) */
	UPROPERTY(EditAnywhere, Category = "Movement Settings", meta = (AllowPrivateAccess = true))
	float MovementSpeed = 100.0f;

	/** The amount of time (in seconds) that the platform will wait after reaching each of its points. */
	UPROPERTY(EditAnywhere, Category = "Movement Settings", meta = (AllowPrivateAccess = true))
	float TimeToWaitWhenReachingTarget = 3.0f;

	//~Start of Auxiliary Variables for platform movement
	int CurrentTargetIndex = 1;

	bool bGoingForward = true;
	bool bIsInWaitTime = false;

	FVector CurrentTargetLocation = FVector::ZeroVector;
	FVector LastTargetLocation = FVector::ZeroVector;

	FTransform InitialTransform = FTransform();
	//~End of Auxiliary Variables for platform movement

	// Variable to count how many triggers are active in the current platform
	int ActiveTriggers = 0;
};
