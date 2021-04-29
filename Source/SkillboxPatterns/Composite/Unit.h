// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Bridge/Weapon.h"
#include "Unit.generated.h"


// Класс Interface для реализаиции паттрна Компоновщик. Базовый интерфейсный класс для всех компонетнов дерева


UCLASS()
class SKILLBOXPATTERNS_API UUnit : public UObject
{
	GENERATED_BODY()

public:
	// Интерфейсная функция
	virtual void MoveToPoint(const FVector Point) {	}

	void SetParent(UUnit* NewParent)
	{
		ParentUnit = NewParent;
	}

	virtual FString GetWeaponName() { return ""; }

	// Эти 2 функции одновременно нужны и для Компоновщика и для Моста
	virtual void Shot() {};
	virtual void HideWeapon() {};

	// Можно добавить еще общих функций, но есть риск что для части наследников они будут пустыми



private:

	// Указатель на родителя. Не обязателен
	UUnit* ParentUnit = nullptr;
};
