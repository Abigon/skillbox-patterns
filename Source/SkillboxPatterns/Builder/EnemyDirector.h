// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemyBuilder.h"
#include "EnemyDirector.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UEnemyDirector : public UObject
{
	GENERATED_BODY()
	
public:
	// Устанавливаем строителя
	void SetBuilder(UEnemyBuilder* NewBuilder) { Builder = NewBuilder; }


	// Создаем простого патрулирующего врага без оружия
	void ConstructSimpleMob(FString Name)
	{
		Builder->Reset(Name);
		Builder->SetAttackAI();
		Builder->SetPatrolAI();
	}

	// Создаем врага с магической атакой, которой ищет врага на территории с одним оружием
	void ConstructMagicMob(FString Name)
	{
		Builder->Reset(Name);
		Builder->SetLeftHandWeapon();
		Builder->SetSeekHeroAI();
		Builder->SetMagicAttackAI();
	}

	// Создаем тяжелого врага в броне с оружием и щитом патрулирующего территорию
	void ConstructHeavyMob(FString Name)
	{
		Builder->Reset(Name);
		Builder->SetLeftHandWeapon();
		Builder->SetShield();
		Builder->SetArmory();
		Builder->SetAttackAI();
		Builder->SetPatrolAI();
	}

private:
	UEnemyBuilder* Builder;
};
