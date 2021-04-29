// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Bridge/Weapon.h"
#include "Unit.generated.h"


// ����� Interface ��� ����������� ������� �����������. ������� ������������ ����� ��� ���� ����������� ������


UCLASS()
class SKILLBOXPATTERNS_API UUnit : public UObject
{
	GENERATED_BODY()

public:
	// ������������ �������
	virtual void MoveToPoint(const FVector Point) {	}

	void SetParent(UUnit* NewParent)
	{
		ParentUnit = NewParent;
	}

	virtual FString GetWeaponName() { return ""; }

	// ��� 2 ������� ������������ ����� � ��� ������������ � ��� �����
	virtual void Shot() {};
	virtual void HideWeapon() {};

	// ����� �������� ��� ����� �������, �� ���� ���� ��� ��� ����� ����������� ��� ����� �������



private:

	// ��������� �� ��������. �� ����������
	UUnit* ParentUnit = nullptr;
};
