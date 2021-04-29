// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "Squad.generated.h"


// Класс Composite. Собирает и управляет деревом

UCLASS()
class SKILLBOXPATTERNS_API USquad : public UUnit
{
	GENERATED_BODY()
	
public:

	// Переопределяем функции для управления отрядом
	virtual void MoveToPoint(const FVector Point) override
	{
		for (auto Unit : SquadUnits)
		{
			UE_LOG(LogTemp, Warning, TEXT("Squad Unit Move To : %s with %s"), *Point.ToString(), *Unit->GetWeaponName());
		}
	}

	virtual void Shot() override
	{
		for (auto Unit : SquadUnits)
		{
			Unit->Shot();
		}
	}

	virtual void HideWeapon() override
	{
		for (auto Unit : SquadUnits)
		{
			Unit->HideWeapon();
		}
	}

	// Добавляем юнит в отряд
	void AddUnit(UUnit* NewUnit)
	{
		if (NewUnit)
		{
			NewUnit->SetParent(this);
			SquadUnits.Add(NewUnit);
		}
	}

	// Удаляем юнит из отряда
	void RemoveUnitAtIndex(int32 Index)
	{
		if (Index < SquadUnits.Num())
		{
			SquadUnits[Index]->SetParent(nullptr);
			SquadUnits.RemoveAt(Index);
		}
	}

private:
	TArray<UUnit*> SquadUnits;
};
