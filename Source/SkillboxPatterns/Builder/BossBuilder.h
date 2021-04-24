// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBuilder.h"
#include "BossBuilder.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UBossBuilder : public UEnemyBuilder
{
	GENERATED_BODY()

public:
	// Создаем новый экземпляр босса
	virtual void Reset(FString Name) override
	{
		ResultBoss = NewObject<UEnemy>();
		ResultBoss->EnemyParts.Empty();
		ResultBoss->EnemyParts.Add(Name);
	}

	// Наполнияем босса элементами
	virtual void SetLeftHandWeapon() override { ResultBoss->EnemyParts.Add("Boss LeftHand Weapon"); }
	virtual void SetRightHandWeapon() override { ResultBoss->EnemyParts.Add("Boss RightHand Weapon"); }
	virtual void SetArmory() override { ResultBoss->EnemyParts.Add("Boss Armory"); }
	virtual void SetShield()  override { ResultBoss->EnemyParts.Add("Boss Shield"); }
	virtual void SetPatrolAI()  override { ResultBoss->EnemyParts.Add("Boss PatrolAI"); }
	virtual void SetSeekHeroAI()  override { ResultBoss->EnemyParts.Add("Boss SeekHeroAI"); }
	virtual void SetAttackAI()  override { ResultBoss->EnemyParts.Add("Boss AttackAI"); }
	virtual void SetMagicAttackAI()  override { ResultBoss->EnemyParts.Add("Boss AmgicAttackAI"); }

	// Возращаем готовой экземпляр босса
	UEnemy* GetResult() { return ResultBoss; }

private:
	UEnemy* ResultBoss;
};
