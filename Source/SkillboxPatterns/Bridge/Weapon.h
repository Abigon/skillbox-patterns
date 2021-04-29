// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Weapon.generated.h"


// Класс Интерфейс для связи конкретной реализации, абстракции (в данном случае с солдатом)

UCLASS()
class SKILLBOXPATTERNS_API UWeapon : public UObject
{
	GENERATED_BODY()
	
public:

	// Объявляем функции которые могут быть перекрыты в конкретной реализации
	virtual void WeaponShot() {};
	virtual void HideWeapon() {};

	virtual FString GetWeaponName() { return WeaponName; }

protected:
	FString WeaponName;

};
