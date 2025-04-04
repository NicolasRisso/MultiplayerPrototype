// Copyright Nicolas Risso 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PZTriggerPlatform.generated.h"

class APZMovingPlatform;
class UBoxComponent;

/** A Trigger that is responsible for firing events for other platforms. */
UCLASS()
class PROJECTZOMBIES_API APZTriggerPlatform : public AActor
{
	GENERATED_BODY()
	
public:	

	APZTriggerPlatform();

protected:
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
private:
	/** Array that stores a reference to all platforms that this trigger will affect. */
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, category = "Trigger Settings", meta = (AllowPrivateAccess = "true"))
	TArray<TObjectPtr<APZMovingPlatform>> PlatformsToTrigger = TArray<TObjectPtr<APZMovingPlatform>>();
	
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> TriggerVolume = nullptr;

	UFUNCTION()
	void TriggerBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void TriggerEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
