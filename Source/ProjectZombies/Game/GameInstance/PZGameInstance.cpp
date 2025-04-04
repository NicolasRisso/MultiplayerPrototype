// Copyright Nicolas Risso 2025. All Rights Reserved.

#include "PZGameInstance.h"

#include "GameplayTagContainer.h"

FGameplayTag UPZGameInstance::ConvertStringToGameplayTag(const FString& TagString)
{
	const FName TagFName(*TagString);
	return FGameplayTag::RequestGameplayTag(TagFName, true);
}
