// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Bridge/Weapon.h"
#include "../Facade/BowArrowShot.h"
#include "BowWeapon.generated.h"


// ������� ������� ��� ������ UBowArrowShot ��� ��� ����� ���� ������������ ������ �� Composite ��� ������ 

UCLASS()
class SKILLBOXPATTERNS_API UBowWeapon : public UWeapon
{
	GENERATED_BODY()
	
public:
	UBowWeapon()
	{
		WeaponName = "Bow";
		BowArrowShot = NewObject<UBowArrowShot>();
	}

	virtual void WeaponShot() override
	{
		// ���������� ���������� �������
		if (BowArrowShot) BowArrowShot->Shot();
	}

	virtual void HideWeapon() override
	{
		// ���������� ���������� �������
		if (BowArrowShot) BowArrowShot->Hide();
	}

private:
	UBowArrowShot* BowArrowShot = nullptr;
};
