// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CreationalPatterns.h"
#include "StructuralPatterns.h"
#include "BehavioralPatterns.h"
#include "SkillboxPatternsGameMode.generated.h"


UCLASS(minimalapi)
class ASkillboxPatternsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASkillboxPatternsGameMode();

	virtual void StartPlay() override;

protected:
	// ��������� ������ ��������
	void RunCreational();
	void RunStructural();
	void RunBehavioral();

	// ���������� ��� ����� ��������� � BP
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Platform")
	EPlatformTypes PlatformType = EPlatformTypes::EPT_Steam;

};



