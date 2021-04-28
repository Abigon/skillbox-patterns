// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Weapon.generated.h"


//  ласс »нтерфейс дл€ св€зи конкретной реализации, абстракции (в данном случае с солдатом)

UCLASS()
class SKILLBOXPATTERNS_API UWeapon : public UObject
{
	GENERATED_BODY()
	
public:

	// ќбъ€вл€ем которые могут быть перекрыты в конкретной реализации
	virtual void Shot() {};
	virtual void Reload() {};

	virtual FString GetWeaponName() { return WeaponName; }

protected:
	FString WeaponName = "";

};
