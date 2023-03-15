// Copyright Epic Games, Inc. All Rights Reserved.

#include "JellyGameProjectGameMode.h"
#include "JellyGameProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJellyGameProjectGameMode::AJellyGameProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
