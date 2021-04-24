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
	// ������������� ���������
	void SetBuilder(UEnemyBuilder* NewBuilder) { Builder = NewBuilder; }


	// ������� �������� �������������� ����� ��� ������
	void ConstructSimpleMob(FString Name)
	{
		Builder->Reset(Name);
		Builder->SetAttackAI();
		Builder->SetPatrolAI();
	}

	// ������� ����� � ���������� ������, ������� ���� ����� �� ���������� � ����� �������
	void ConstructMagicMob(FString Name)
	{
		Builder->Reset(Name);
		Builder->SetLeftHandWeapon();
		Builder->SetSeekHeroAI();
		Builder->SetMagicAttackAI();
	}

	// ������� �������� ����� � ����� � ������� � ����� �������������� ����������
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
