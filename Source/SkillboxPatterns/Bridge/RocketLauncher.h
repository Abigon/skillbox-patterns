// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "RocketLauncher.generated.h"


// ���������� ���������� �������� ������ ������������� �� ����������

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
		// ���������� ���������� �������
	}

	virtual void Reload() override
	{
		// ���������� ���������� �������
	}
};
