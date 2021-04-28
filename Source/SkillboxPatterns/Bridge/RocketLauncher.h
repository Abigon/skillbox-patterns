// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "RocketLauncher.generated.h"


// Конкретная реализация варианта оружия наследованная от интерфейса

UCLASS()
class SKILLBOXPATTERNS_API URocketLauncher : public UWeapon
{
	GENERATED_BODY()
	
public:
	URocketLauncher()
	{
		WeaponName += "RocketLauncher";
	}

	virtual void Shot() override 
	{
		// Конкретная реализация функции
	}

	virtual void Reload() override
	{
		// Конкретная реализация функции
	}
};
