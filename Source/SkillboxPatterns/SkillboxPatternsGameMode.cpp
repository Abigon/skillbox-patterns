// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillboxPatternsGameMode.h"
#include "SkillboxPatternsCharacter.h"
#include "AbstractFactory/AndroidFactory.h"
#include "AbstractFactory/IOSFactory.h"
#include "AbstractFactory/SteamFactory.h"
#include "Builder/BossBuilder.h"
#include "Builder/MobBuilder.h"
#include "Builder/EnemyDirector.h"
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

	// AbstractFactory
	InitPlatform();

	// Builder
	InitEnemies();
}

void ASkillboxPatternsGameMode::InitEnemies()
{
	TArray<UEnemy*> Enemies;

	UEnemyDirector* Director = NewObject<UEnemyDirector>();
	UMobBuilder* MobBuilder = NewObject<UMobBuilder>();

	// ������� �������� ���� ����� ���������
	Director->SetBuilder(MobBuilder);
	Director->ConstructSimpleMob("Simple Mob");
	Enemies.Add(MobBuilder->GetResult());

	// ������� ����� ���������� ������ ����� ���������
	Director->ConstructMagicMob("Magic Mob");
	Enemies.Add(MobBuilder->GetResult());

	// ������� �������� ���� ����� ���������
	Director->ConstructHeavyMob("Heavy Mob");
	Enemies.Add(MobBuilder->GetResult());

	// ������� ���������� ���� ��� ���������
	MobBuilder->Reset("Custom Mob");
	MobBuilder->SetLeftHandWeapon();
	MobBuilder->SetRightHandWeapon();
	MobBuilder->SetArmory();
	MobBuilder->SetSeekHeroAI();
	MobBuilder->SetAttackAI();
	Enemies.Add(MobBuilder->GetResult());

	// ������� ����� ��� ���������
	UBossBuilder* BossBuilder = NewObject<UBossBuilder>();
	BossBuilder->Reset("Boss 1");
	BossBuilder->SetLeftHandWeapon();
	BossBuilder->SetShield();
	BossBuilder->SetArmory();
	BossBuilder->SetSeekHeroAI();
	BossBuilder->SetAttackAI();
	BossBuilder->SetMagicAttackAI();
	Enemies.Add(BossBuilder->GetResult());

	// ������� ����� � ����������
	Director->SetBuilder(BossBuilder);
	Director->ConstructMagicMob("Boss 2");
	Enemies.Add(BossBuilder->GetResult());


	UE_LOG(LogTemp, Warning, TEXT("----  Builder  ----"));

	for (auto Enemy : Enemies)
	{
		Enemy->ListEnemyParts();
	}
	UE_LOG(LogTemp, Warning, TEXT(" "));
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
	UE_LOG(LogTemp, Warning, TEXT("----  AbstractFactory  ----"));
	PlatformAchieviments->SetAchievmentComplite("50 Enemies killed");
	PlatformChat->ConnectToChat();
	PlatformChat->SendMessage("Hello!!!!");
	PlatformTop->AddToTop(1204);
	UE_LOG(LogTemp, Warning, TEXT(" "));
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