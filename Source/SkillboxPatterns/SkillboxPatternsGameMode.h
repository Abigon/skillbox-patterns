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
	// ���������� ��� ���������
	void DetectPlatformType();

	// ������� ������ � ����������� �� ���������
	void InitPlatform();

	// ����������� ������
	void InitEnemies();

	// ���������� ��������
	void InitConnect();

	// ���������� ���
	void InitLoot();

	// ����������� � ����
	void InitSquadUnitsBridge();

	// Facade
	void InitBowArrows();


	// ��������� ������ ��������
	void RunCreational();
	void RunStructural();
	void RunBehavioral();

	// ���������� ��� ����� ��������� � BP
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Platform")
	EPlatformTypes PlatformType = EPlatformTypes::EPT_Steam;

private:
	class UBaseFactory* PlatformFactory = nullptr;
	class UBaseAchievements* PlatformAchieviments = nullptr;
	class UBaseChat* PlatformChat = nullptr;
	class UBaseTop* PlatformTop = nullptr;
};



