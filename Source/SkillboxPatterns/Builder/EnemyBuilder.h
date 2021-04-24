// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Enemy.h"
#include "EnemyBuilder.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UEnemyBuilder : public UObject
{
	GENERATED_BODY()

public:
	virtual void Reset(FString Name) {};
	virtual void SetLeftHandWeapon() {};
	virtual void SetRightHandWeapon() {};
	virtual void SetArmory() {};
	virtual void SetShield() {};
	virtual void SetPatrolAI() {};
	virtual void SetSeekHeroAI() {};
	virtual void SetAttackAI() {};
	virtual void SetMagicAttackAI() {};
};
