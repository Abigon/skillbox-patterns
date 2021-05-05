// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillboxPatternsGameMode.h"
#include "SkillboxPatternsCharacter.h"
#include "Singleton/SingletonConnector.h"
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

	// Singlton
	auto Connector = USingletonConnector::Get("GameMode");
}

void ASkillboxPatternsGameMode::SaveGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game saved at Slot #1"));
}

void ASkillboxPatternsGameMode::LoadGame()
{
	UE_LOG(LogTemp, Warning, TEXT("Game loaded from Slot #1"));
}

