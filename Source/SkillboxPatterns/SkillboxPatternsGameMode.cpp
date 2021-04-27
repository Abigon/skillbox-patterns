// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillboxPatternsGameMode.h"
#include "SkillboxPatternsCharacter.h"
#include "AbstractFactory/AndroidFactory.h"
#include "AbstractFactory/IOSFactory.h"
#include "AbstractFactory/SteamFactory.h"
#include "Builder/BossBuilder.h"
#include "Builder/MobBuilder.h"
#include "Builder/EnemyDirector.h"
#include "Prototype/LootManager.h"
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

	// AbstractFactory
	InitPlatform();

	// Builder
	InitEnemies();

	// Prototype
	InitLoot();
	
	// Singlton
	InitConnect();
}


void ASkillboxPatternsGameMode::InitConnect()
{

	auto Connector = USingletonConnector::Get("GameMode");

}

void ASkillboxPatternsGameMode::InitLoot()
{
	auto LootManager = NewObject<ULootManager>();

	UE_LOG(LogTemp, Warning, TEXT("----  Prototype  ----"));

	TArray<UPrototypeItem*> Loots;
	Loots.Add(LootManager->GetNewLootItem(EItemTypes::EIT_GreatHealthPoiton));
	Loots.Add(LootManager->GetNewLootItem(EItemTypes::EIT_LightItem));
	Loots.Add(LootManager->GetNewLootItem(EItemTypes::EIT_SmallHealthPoiton));
	Loots.Add(LootManager->GetNewLootItem(EItemTypes::EIT_LightItem));
	Loots.Add(LootManager->GetNewLootItem(EItemTypes::EIT_GreatHealthPoiton));

	for (auto Loot : Loots)
	{
		Loot->PrintItem();
	}
	UE_LOG(LogTemp, Warning, TEXT(" "));
}

void ASkillboxPatternsGameMode::InitEnemies()
{
	TArray<UEnemy*> Enemies;

	auto Director = NewObject<UEnemyDirector>();
	auto MobBuilder = NewObject<UMobBuilder>();

	// Создаем простого моба через директора
	Director->SetBuilder(MobBuilder);
	Director->ConstructSimpleMob("Simple Mob");
	Enemies.Add(MobBuilder->GetResult());

	// Создаем мобас магической атакой через директора
	Director->ConstructMagicMob("Magic Mob");
	Enemies.Add(MobBuilder->GetResult());

	// Создаем тяжелого моба через директора
	Director->ConstructHeavyMob("Heavy Mob");
	Enemies.Add(MobBuilder->GetResult());

	// Создаем кастомного моба без директора
	MobBuilder->Reset("Custom Mob");
	MobBuilder->SetLeftHandWeapon();
	MobBuilder->SetRightHandWeapon();
	MobBuilder->SetArmory();
	MobBuilder->SetSeekHeroAI();
	MobBuilder->SetAttackAI();
	Enemies.Add(MobBuilder->GetResult());

	// Создаем босса без директора
	auto BossBuilder = NewObject<UBossBuilder>();
	BossBuilder->Reset("Boss 1");
	BossBuilder->SetLeftHandWeapon();
	BossBuilder->SetShield();
	BossBuilder->SetArmory();
	BossBuilder->SetSeekHeroAI();
	BossBuilder->SetAttackAI();
	BossBuilder->SetMagicAttackAI();
	Enemies.Add(BossBuilder->GetResult());

	// Создаем босса с директором
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

	// После создания фабрики, создаем экземпляры, необходимые для данной платформы
	PlatformAchieviments = PlatformFactory->GetAchievements();
	PlatformChat = PlatformFactory->GetChat();
	PlatformTop = PlatformFactory->GetTop();

	//Тестируем функции. Должны выводится в зависимости от выбраной платформы
	UE_LOG(LogTemp, Warning, TEXT("----  AbstractFactory  ----"));
	PlatformAchieviments->SetAchievmentComplite("50 Enemies killed");
	PlatformChat->ConnectToChat();
	PlatformChat->SendMessage("Hello!!!!");
	PlatformTop->AddToTop(1204);
	UE_LOG(LogTemp, Warning, TEXT(" "));
}

void ASkillboxPatternsGameMode::DetectPlatformType()
{
	// Создаем фабрику в зависимости от платформы и присваиваем ее переменной

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