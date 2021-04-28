// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bow.h"
#include "Arrow.h"
#include "BowArrowShot.generated.h"


// Фасад для простого использованию лука со стрелами

UCLASS()
class SKILLBOXPATTERNS_API UBowArrowShot : public UObject
{
	GENERATED_BODY()
	
public:

	// Создание лука + стрела
	UBowArrowShot() 
	{
		Bow = NewObject<UBow>();			// Создаем лук
		Bow->Equip();						// Выбираем как оружие

		CurrentArrow = NewObject<UArrow>();	// Создаем первую стрелу
		CurrentArrow->Arming(Bow);			// Присоединяем стрелу к луку
	}

	// Выстрел
	void Shot() 
	{
		Bow->PrepareToShot();				// Натягиваем тетиву
		Bow->Shot();						// Стреляем
		CurrentArrow->MoveTo(FVector(0));	// Стрела движется
		CurrentArrow = nullptr;				// Этой строки тут быть не должно. Срабатывает декоратор и удаляет стрелу. Тут удаляется для очистки памяти
		
		CurrentArrow = NewObject<UArrow>();	// Создаем новую стрелу
		CurrentArrow->Arming(Bow);			// Присоединяем стрелу к луку
	}

	// Прячем лук
	void Hide()
	{
		Bow->Unarm();						// прячем лук
		CurrentArrow = nullptr;				// Тут должно быть что-то вроде - delete CurrentArrow -. Но UE крашится. В данном случае не критично,  
											// так как сборщик мусора все равно удалит объект, но не красиво.
	}

private:
	UBow* Bow = nullptr;
	UArrow* CurrentArrow = nullptr;
};
