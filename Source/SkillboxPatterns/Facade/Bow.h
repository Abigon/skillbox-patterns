// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bow.generated.h"

// Класс лука. 

UCLASS()
class SKILLBOXPATTERNS_API UBow : public UObject
{
	GENERATED_BODY()

public:

	void Equip()			// Выбор лука как оружия персонажем
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Equip"));
	}

	void Unarm()			// Отмена лука как оружия персонажем
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Unarm"));
	}

	void PrepareToShot()	// Подготовка к выстрелу (натягивание тетивы)
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Prepare To Shot"));
	}

	void Shot() 			// Выстрел 
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Shot"));
	}
};
