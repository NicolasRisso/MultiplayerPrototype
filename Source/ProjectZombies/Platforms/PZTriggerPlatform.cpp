// Copyright Nicolas Risso 2025. All Rights Reserved.

#include "PZTriggerPlatform.h"

#include "PZMovingPlatform.h"
#include "Components/BoxComponent.h"
#include "Interface/TriggerCounterInterface.h"

APZTriggerPlatform::APZTriggerPlatform()
{
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	
	if (!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;
	
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APZTriggerPlatform::TriggerBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APZTriggerPlatform::TriggerEnd);
}

void APZTriggerPlatform::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	TriggerVolume->OnComponentBeginOverlap.RemoveDynamic(this, &APZTriggerPlatform::TriggerBegin);
	TriggerVolume->OnComponentEndOverlap.RemoveDynamic(this, &APZTriggerPlatform::TriggerEnd);
}

void APZTriggerPlatform::TriggerBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (TObjectPtr Platform : PlatformsToTrigger)
	{
		if (Platform && Platform->Implements<UTriggerCounterInterface>())
		{
			ITriggerCounterInterface::Execute_AddActiveTrigger(Platform);
		}
	}
}

void APZTriggerPlatform::TriggerEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	for (TObjectPtr Platform : PlatformsToTrigger)
	{
		if (Platform && Platform->Implements<UTriggerCounterInterface>())
		{
			ITriggerCounterInterface::Execute_RemoveActiveTrigger(Platform);
		}
	}
}
