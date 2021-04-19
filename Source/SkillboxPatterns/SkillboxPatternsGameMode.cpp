// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillboxPatternsGameMode.h"
#include "SkillboxPatternsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASkillboxPatternsGameMode::ASkillboxPatternsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
