// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Weapon.generated.h"


// ����� ��������� ��� ����� ���������� ����������, ���������� (� ������ ������ � ��������)

UCLASS()
class SKILLBOXPATTERNS_API UWeapon : public UObject
{
	GENERATED_BODY()
	
public:

	// ��������� ������� ����� ���� ��������� � ���������� ����������
	virtual void Shot() {};
	virtual void Reload() {};

	virtual FString GetWeaponName() { return WeaponName; }

protected:
	FString WeaponName = "";

};
