// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VisitorTemp.h"
#include "../Composite/Soldier.h"
#include "../Composite/Squad.h"
#include "HealVisitor.generated.h"

// Конкретная реализация посетителя для наследников Unit

UCLASS()
class SKILLBOXPATTERNS_API UHealVisitor : public UVisitorTemp
{
	GENERATED_BODY()
	
public:

	// Функциии для посещения классов
	// Реализация посетителя для конкретного класса. Посетитель знает о функциях, доступных в классе 
	// И в зависимости от класса помет по разному его обрабатывать

	virtual void VisitSoldier(USoldier* Soldier) override
	{
		Soldier->Heal();
	}

	virtual void VisitSquad(USquad* Squad) override 
	{
		Squad->HealSquad();
	}
};
