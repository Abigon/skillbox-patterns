// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "Soldier.generated.h"

// ����� Leaf (������� ���� ������). ����� ���� ��������� ����� �������

// ����� ���������� ��� ���������� �������� ����. �� ���������� �������� ������ ���������� ������� ����������. � ������ ������ ������


UCLASS()
class SKILLBOXPATTERNS_API USoldier : public UUnit
{
	GENERATED_BODY()
	
public:
	virtual void MoveToPoint(const FVector Point) override
	{
		UE_LOG(LogTemp, Warning, TEXT("Soldier Move To : %s with %s"), *Point.ToString(), *GetWeaponName());
	}

	// ������� ��� ���������� �����
	void AddWeapon(UWeapon* Weapon) { UnitWeapon = Weapon; }

	virtual void Shot() override
	{
		UnitWeapon->Shot();
	}

	virtual void Reload() override
	{
		UnitWeapon->Reload();
	}

	virtual FString GetWeaponName() override { return UnitWeapon->GetWeaponName(); }

protected:
	UWeapon* UnitWeapon = nullptr;

	// ����� �������� ��� ������ ���������� ��� ����� ������ Leaf
private:
};
