// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bow.h"
#include "Arrow.h"
#include "BowArrowShot.generated.h"


// ����� ��� �������� ������������� ���� �� ��������

UCLASS()
class SKILLBOXPATTERNS_API UBowArrowShot : public UObject
{
	GENERATED_BODY()
	
public:

	// �������� ���� + ������
	UBowArrowShot() 
	{
		Bow = NewObject<UBow>();			// ������� ���
		Bow->Equip();						// �������� ��� ������

		CurrentArrow = NewObject<UArrow>();	// ������� ������ ������
		CurrentArrow->Arming(Bow);			// ������������ ������ � ����
	}

	// �������
	void Shot() 
	{
		Bow->PrepareToShot();				// ���������� ������
		Bow->Shot();						// ��������
		CurrentArrow->MoveTo(FVector(0));	// ������ ��������
		CurrentArrow = nullptr;				// ���� ������ ��� ���� �� ������. ����������� ��������� � ������� ������. ��� ��������� ��� ������� ������
		
		CurrentArrow = NewObject<UArrow>();	// ������� ����� ������
		CurrentArrow->Arming(Bow);			// ������������ ������ � ����
	}

	// ������ ���
	void Hide()
	{
		Bow->Unarm();						// ������ ���
		CurrentArrow = nullptr;				// ��� ������ ���� ���-�� ����� - delete CurrentArrow -. �� UE ��������. � ������ ������ �� ��������,  
											// ��� ��� ������� ������ ��� ����� ������ ������, �� �� �������.
	}

private:
	UBow* Bow = nullptr;
	UArrow* CurrentArrow = nullptr;
};
