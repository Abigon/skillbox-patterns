// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bow.h"
#include "Arrow.generated.h"


// Класс Стрелы. Допускаем, что обработка попадания и удаления стрелы работает в других объектах через декоратор

UCLASS()
class SKILLBOXPATTERNS_API UArrow : public UObject
{
	GENERATED_BODY()

public:

	~UArrow()
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrow delete"));
	}

	void MoveTo(FVector Point)		// Движение стрелы после выстрела в точку
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrow Move To : %s"), *Point.ToString());
	}	

	void Arming(UBow* Bow)			// Присоединение стрелы к луку для натяжения тетивы
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrow Arming"));
	}
};
