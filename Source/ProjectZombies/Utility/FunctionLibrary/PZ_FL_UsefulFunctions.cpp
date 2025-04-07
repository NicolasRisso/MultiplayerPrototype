// Copyright Nicolas Risso 2025. All Rights Reserved.

#include "PZ_FL_UsefulFunctions.h"

#include "GameplayTagContainer.h"

FGameplayTag UPZ_FL_UsefulFunctions::ConvertStringToGameplayTag(const FString& TagString)
{
	const FName TagFName(*TagString);
	return FGameplayTag::RequestGameplayTag(TagFName, true);
}
