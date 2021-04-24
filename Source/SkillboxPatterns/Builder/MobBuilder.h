// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBuilder.h"
#include "MobBuilder.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UMobBuilder : public UEnemyBuilder
{
	GENERATED_BODY()
	
public:
	// Создаем новый экземпляр врага
	virtual void Reset(FString Name) override
	{
		ResultEnemy = NewObject<UEnemy>();
		ResultEnemy->EnemyParts.Empty();
		ResultEnemy->EnemyParts.Add(Name);
	}

	// Наполнияем врага элементами
	virtual void SetLeftHandWeapon() override { ResultEnemy->EnemyParts.Add("LeftHand Weapon"); }
	virtual void SetRightHandWeapon() override { ResultEnemy->EnemyParts.Add("RightHand Weapon"); }
	virtual void SetArmory() override { ResultEnemy->EnemyParts.Add("Armory"); }
	virtual void SetShield()  override { ResultEnemy->EnemyParts.Add("Shield"); }
	virtual void SetPatrolAI()  override { ResultEnemy->EnemyParts.Add("PatrolAI"); }
	virtual void SetSeekHeroAI()  override { ResultEnemy->EnemyParts.Add("SeekHeroAI"); }
	virtual void SetAttackAI()  override { ResultEnemy->EnemyParts.Add("AttackAI"); }
	virtual void SetMagicAttackAI()  override { ResultEnemy->EnemyParts.Add("MagicAttackAI"); }

	// Возращаем готовой экземпляр врага
	UEnemy* GetResult() { return ResultEnemy; }

private:
	UEnemy* ResultEnemy;
};
