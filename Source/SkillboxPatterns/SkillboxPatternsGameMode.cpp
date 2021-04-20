// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillboxPatternsGameMode.h"
#include "SkillboxPatternsCharacter.h"
#include "AbstractFactory/AndroidFactory.h"
#include "AbstractFactory/IOSFactory.h"
#include "AbstractFactory/SteamFactory.h"
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

	InitPlatform();
}

void ASkillboxPatternsGameMode::InitPlatform()
{
	DetectPlatformType();

	if (!PlatformFactory) return;

	// ����� �������� �������, ������� ����������, ����������� ��� ������ ���������
	PlatformAchieviments = PlatformFactory->GetAchievements();
	PlatformChat = PlatformFactory->GetChat();
	PlatformTop = PlatformFactory->GetTop();

	//��������� �������. ������ ��������� � ����������� �� �������� ���������
	PlatformAchieviments->SetAchievmentComplite("50 Enemies killed");
	PlatformChat->ConnectToChat();
	PlatformChat->SendMessage("Hello!!!!");
	PlatformTop->AddToTop(1204);
}

void ASkillboxPatternsGameMode::DetectPlatformType()
{
	// ������� ������� � ����������� �� ��������� � ����������� �� ����������

	switch (PlatformType)
	{
	case EPlatformTypes::EPT_Android:
		PlatformFactory = NewObject<UAndroidFactory>();
		break;

	case EPlatformTypes::EPT_iOS:
		PlatformFactory = NewObject<UIOSFactory>();
		break;

	case EPlatformTypes::EPT_Steam:
		PlatformFactory = NewObject<USteamFactory>();
		break;

	default:
		break;
	}
}