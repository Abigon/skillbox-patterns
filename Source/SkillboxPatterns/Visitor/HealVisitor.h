// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VisitorTemp.h"
#include "../Composite/Soldier.h"
#include "../Composite/Squad.h"
#include "HealVisitor.generated.h"

// ���������� ���������� ���������� ��� ����������� Unit

UCLASS()
class SKILLBOXPATTERNS_API UHealVisitor : public UVisitorTemp
{
	GENERATED_BODY()
	
public:

	// �������� ��� ��������� �������
	// ���������� ���������� ��� ����������� ������. ���������� ����� � ��������, ��������� � ������ 
	// � � ����������� �� ������ ����� �� ������� ��� ������������

	virtual void VisitSoldier(USoldier* Soldier) override
	{
		Soldier->Heal();
	}

	virtual void VisitSquad(USquad* Squad) override 
	{
		Squad->HealSquad();
	}
};
