// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "Soldier.generated.h"

// Класс Leaf (кончный лист дерева). Может быть несколько таких классов

// Класс Абстракции для реализации паттерна Мост. Он делегирует реальную работу связанному объекту раелизации. В данном случае оружию


UCLASS()
class SKILLBOXPATTERNS_API USoldier : public UUnit
{
	GENERATED_BODY()
	
public:
	virtual void MoveToPoint(const FVector Point) override
	{
		UE_LOG(LogTemp, Warning, TEXT("Soldier Move To : %s with %s"), *Point.ToString(), *GetWeaponName());
	}

	// Функции для реализации Моста
	void AddWeapon(UWeapon* Weapon) { UnitWeapon = Weapon; }

	virtual void Shot() override
	{
		UnitWeapon->WeaponShot();
	}

	virtual void HideWeapon() override
	{
		UnitWeapon->HideWeapon();
	}

	virtual FString GetWeaponName() override { return UnitWeapon->GetWeaponName(); }

	// Функция для Посетителя
	virtual void Accept(UVisitorTemp* Visitor) override 
	{
		Visitor->VisitSoldier(this);
	}

	// Функция, которая будет вызываться посетителем
	void Heal() 
	{
		UE_LOG(LogTemp, Warning, TEXT("Soldier was heal by Visitor"));
	}

protected:
	UWeapon* UnitWeapon = nullptr;

	// Можно добавить еще логику конкретную для этого класса Leaf
private:
};
