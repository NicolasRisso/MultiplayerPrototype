// Copyright Nicolas Risso 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PZ_FL_UsefulFunctions.generated.h"

struct FGameplayTag;

UCLASS()
class PROJECTZOMBIES_API UPZ_FL_UsefulFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Utility|Tags")
	static FGameplayTag ConvertStringToGameplayTag(const FString& TagString);
};
