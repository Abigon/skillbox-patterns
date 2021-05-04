// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VisitorTemp.generated.h"

// Интерфейс для посетителя наследников от Unit

UCLASS()
class SKILLBOXPATTERNS_API UVisitorTemp : public UObject
{
	GENERATED_BODY()
	
public:

	// Функциии для посещения классов

	virtual void VisitSoldier(class USoldier* Soldier) {};

	virtual void VisitSquad(class USquad* Squad) {};
};
