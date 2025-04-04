// Copyright Nicolas Risso 2025. All Rights Reserved.

#include "PZMovingPlatform.h"

APZMovingPlatform::APZMovingPlatform()
{
	SetMobility(EComponentMobility::Movable);

	if (HasAuthority()) PrimaryActorTick.bCanEverTick = true;
}

void APZMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	TargetLocations.Insert(FVector(0.0f, 0.0f, 0.0f), 0);

	InitialTransform = GetActorTransform();
	
	CurrentTargetLocation = InitialTransform.TransformPosition(TargetLocations[CurrentTargetIndex]);
	LastTargetLocation = GetActorLocation();
	
	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
}

void APZMovingPlatform::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!HasAuthority()) return;
	if (bIsInWaitTime) return;
	if (bNeedTriggerToMove && ActiveTriggers < MinimumTriggersToMove) return;

	FVector Location = GetActorLocation();

	const float JourneyLength = (CurrentTargetLocation - LastTargetLocation).Size();
	const float JourneyTravelled = (Location - LastTargetLocation).Size();
	if (JourneyTravelled >= JourneyLength)
	{
		//Platform logic if it is set to Go Forward and Backwards
		if (MovementType == EMovingPlatformType::GoForwardAndBackward)
		{
			if (bGoingForward && CurrentTargetIndex + 1 >= TargetLocations.Num()) bGoingForward = false;
			if (!bGoingForward && CurrentTargetIndex - 1 < 0) bGoingForward = true;
			CurrentTargetIndex += bGoingForward ? 1 : -1;
		}
		//Platform logic if it is set to Loop
		else if (MovementType == EMovingPlatformType::Loop)
		{
			if (bGoingForward && CurrentTargetIndex + 1 >= TargetLocations.Num()) CurrentTargetIndex = 0;
			else CurrentTargetIndex++;
		}
		
		LastTargetLocation = CurrentTargetLocation;
		CurrentTargetLocation = InitialTransform.TransformPosition(TargetLocations[CurrentTargetIndex]);

		//Create TimeHandler to wait for the platform to move
		if (TimeToWaitWhenReachingTarget > 0.0f)
		{
			bIsInWaitTime = true;
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]()
			{
				bIsInWaitTime = false;
			}), TimeToWaitWhenReachingTarget, false);
		}

	}
	
	const FVector Direction = (CurrentTargetLocation - LastTargetLocation).GetSafeNormal();
	Location += Direction * MovementSpeed * DeltaSeconds;
	SetActorLocation(Location);	
}

void APZMovingPlatform::AddActiveTrigger_Implementation()
{
	ActiveTriggers++;
	if (ActiveTriggers >= MinimumTriggersToMove) StartedMoving();
}

void APZMovingPlatform::RemoveActiveTrigger_Implementation()
{
	if (ActiveTriggers > 0) ActiveTriggers--;
	if (ActiveTriggers < MinimumTriggersToMove) StoppedMoving();
}
