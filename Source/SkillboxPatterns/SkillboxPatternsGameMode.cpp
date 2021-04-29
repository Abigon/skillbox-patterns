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
#include "Composite/Squad.h"
#include "Composite/Soldier.h"
#include "Bridge/Rifle.h"
#include "Bridge/RocketLauncher.h"
#include "Facade/BowArrowShot.h"
#include "Proxy/BowArrowShotLog.h"
#include "Adapter/BowWeapon.h"
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

}

void ASkillboxPatternsGameMode::RunStructural()
{
	// Компоновщик и Мост
	InitSquadUnitsBridge();

	// Фасад
	InitBowArrows();

	// Заместитель
	InitBowArrowsLog();
	
	// Адаптер
	InitBowWeapon();
}

void ASkillboxPatternsGameMode::InitBowWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("----  Adapter ----"));

	// Создаем солдата и добавляем ему лук 
	auto Soldier1 = NewObject<USoldier>();
	Soldier1->AddWeapon(NewObject<UBowWeapon>());

	//Отправляем из к точке для вывода лога
	Soldier1->MoveToPoint(FVector(33));

	UE_LOG(LogTemp, Warning, TEXT("   "));
}

void ASkillboxPatternsGameMode::InitBowArrowsLog()
{
	UE_LOG(LogTemp, Warning, TEXT("---- Proxy 1 ----"));
	
	auto BALog = NewObject<UBowArrowShotLog>();
	BALog->Shot();
	BALog->Hide();

	UE_LOG(LogTemp, Warning, TEXT("   "));
}

void ASkillboxPatternsGameMode::InitBowArrows()
{
	UE_LOG(LogTemp, Warning, TEXT("---- Facade ----"));

	auto BA = NewObject<UBowArrowShot>();
	BA->Shot();
	BA->Hide();

	UE_LOG(LogTemp, Warning, TEXT("   "));
}

void ASkillboxPatternsGameMode::InitSquadUnitsBridge()
{
	UE_LOG(LogTemp, Warning, TEXT("----  Composite & Bridge ----"));

	// Создаем солдат и добавляем им оружие
	auto Soldier1 = NewObject<USoldier>();
	Soldier1->AddWeapon(NewObject<URifle>());
	auto Soldier2 = NewObject<USoldier>();
	Soldier2->AddWeapon(NewObject<URocketLauncher>());
	auto Soldier3 = NewObject<USoldier>();
	Soldier3->AddWeapon(NewObject<URifle>());

	// Создаем отряд, оружие не добавляем
	auto Squad = NewObject<USquad>();

	// Добавляет жвух солдат в отряд, один остается свободным
	Squad->AddUnit(Soldier1);
	Squad->AddUnit(Soldier2);

	// Отправляем свободного солдата к точке
	Soldier3->MoveToPoint(FVector(1));

	//Отправляем отряд к точке
	Squad->MoveToPoint(FVector(10));

	//Отправляем солдата из отряда к точке
	Soldier1->MoveToPoint(FVector(33));

	UE_LOG(LogTemp, Warning, TEXT("   "));
}

void ASkillboxPatternsGameMode::RunCreational()
{
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
	LootManager->InitLootManager();

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