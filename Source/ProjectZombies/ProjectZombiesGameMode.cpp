// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectZombiesGameMode.h"
#include "ProjectZombiesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectZombiesGameMode::AProjectZombiesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
