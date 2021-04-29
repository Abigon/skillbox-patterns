// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Facade/BowArrowShot.h"
#include "BowArrowShotLog.generated.h"


// Класс Заместитель. Добавляет логирование использования класс UBowArrowShot. 
// При уничтожении класса выводится лог, или можно сделать сохранеие в файл и т.п.

UCLASS()
class SKILLBOXPATTERNS_API UBowArrowShotLog : public UObject
{
	GENERATED_BODY()
	
public:
	UBowArrowShotLog()
	{
		LogStrings.Empty();

		BowArrowShot = NewObject<UBowArrowShot>();				// Создаем класс, который замещаем
		if (BowArrowShot)
		{
			LogStrings.Add("Init Object");						// Логируем инициализацию
		}
		else
		{
			LogStrings.Add("Object Initialization Error");		// Логируем ошибку инициализации
		}
	}

	~UBowArrowShotLog()
	{
		// При уничтожении выводим лог
		UE_LOG(LogTemp, Warning, TEXT("---- Proxy 2 ----"));
		
		for (auto LogString : LogStrings)
		{
			UE_LOG(LogTemp, Warning, TEXT("UBowArrowShotLog: %s"), *LogString);
		}

		UE_LOG(LogTemp, Warning, TEXT("  "));
	}

	// Выстрел
	void Shot()
	{
		if (BowArrowShot)
		{
			BowArrowShot->Shot();		
			LogStrings.Add("Shot");				
		}
		else
		{
			LogStrings.Add("Shot Error");		
		}
	}

	// Прячем лук
	void Hide()
	{
		if (BowArrowShot)
		{
			BowArrowShot->Hide();						
			LogStrings.Add("Bow Hide");
		}
		else
		{
			LogStrings.Add("Hide Error");
		}
	}

private:
	UBowArrowShot* BowArrowShot = nullptr;
	TArray<FString> LogStrings;
};
