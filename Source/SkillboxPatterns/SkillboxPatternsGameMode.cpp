// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillboxPatternsGameMode.h"
#include "SkillboxPatternsCharacter.h"
#include "UObject/ConstructorHelpers.h"


ASkillboxPatternsGameMode::ASkillboxPatternsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASkillboxPatternsGameMode::StartPlay()
{
	Super::StartPlay();

	RunCreational();
	RunStructural();
	RunBehavioral();
}

void ASkillboxPatternsGameMode::RunBehavioral()
{
	auto BehavioralPatterns = NewObject<UBehavioralPatterns>();

	if (BehavioralPatterns) BehavioralPatterns->InitBehavioralPatterns();
}

void ASkillboxPatternsGameMode::RunStructural()
{
	auto StructuralPatterns = NewObject<UStructuralPatterns>();

	if (StructuralPatterns) StructuralPatterns->InitStructuralPatterns();
}

void ASkillboxPatternsGameMode::RunCreational()
{
	auto CreationalPatterns = NewObject<UCreationalPatterns>();

	if (CreationalPatterns) CreationalPatterns->InitCreationalPatterns(PlatformType);
}

