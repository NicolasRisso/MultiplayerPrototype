// Copyright Nicolas Risso 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TriggerCounterInterface.generated.h"

/** Interface responsible for counting the number of active triggers in a certain UObject. */
UINTERFACE(MinimalAPI)
class UTriggerCounterInterface : public UInterface
{
	GENERATED_BODY()
};

/** Interface for classes that need to track active triggers. */
class ITriggerCounterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void AddActiveTrigger();
	virtual void AddActiveTrigger_Implementation() = 0;

	UFUNCTION(BlueprintNativeEvent)
	void RemoveActiveTrigger();
	virtual void RemoveActiveTrigger_Implementation() = 0;
};