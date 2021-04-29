// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Rifle.generated.h"

// ���������� ���������� �������� ������ ������������� �� ����������

UCLASS()
class SKILLBOXPATTERNS_API URifle : public UWeapon
{
	GENERATED_BODY()
	
public:
	URifle()
	{
		WeaponName = "Rifle";
	}

	virtual void WeaponShot() override
	{
		// ���������� ���������� �������
	}

	virtual void HideWeapon() override
	{
		// ���������� ���������� �������
	}

};
