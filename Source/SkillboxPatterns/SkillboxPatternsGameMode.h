// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkillboxPatternsGameMode.generated.h"


UENUM(Blueprinttype)
enum class EPlatformTypes : uint8
{
	EPT_Android UMETA(DisplayName = "Android"),
	EPT_iOS UMETA(DisplayName = "iOS"),
	EPT_Steam UMETA(DisplayName = "Steam"),
	EPT_MAX UMETA(DisplayName = "DefaultMAX")
};


UCLASS(minimalapi)
class ASkillboxPatternsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASkillboxPatternsGameMode();

	virtual void StartPlay() override;

protected:
	// Определяем тип платформы
	void DetectPlatformType();

	// Создаем классы в зависимости от платформы
	void InitPlatform();

	// Геренрируем врагов
	void InitEnemies();

	// Подключаем одиночку
	void InitConnect();

	// Генерируем лут
	void InitLoot();

	// Компоновщик и мост
	void InitSquadUnitsBridge();

	// Facade
	void InitBowArrows();


	// Запускаем разные паттерны
	void RunCreational();
	void RunStructural();
	void RunBehavioral();

	// Переменная для смены платформы в BP
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Platform")
	EPlatformTypes PlatformType = EPlatformTypes::EPT_Steam;

private:
	class UBaseFactory* PlatformFactory = nullptr;
	class UBaseAchievements* PlatformAchieviments = nullptr;
	class UBaseChat* PlatformChat = nullptr;
	class UBaseTop* PlatformTop = nullptr;
};



