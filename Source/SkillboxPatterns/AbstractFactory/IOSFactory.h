// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseFactory.h"
#include "IOSAchievements.h"
#include "IOSChat.h"
#include "IOSTop.h"
#include "IOSFactory.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UIOSFactory : public UBaseFactory
{
	GENERATED_BODY()
	
public:

	// Создаем конектор для ачивок
	virtual UBaseAchievements* GetAchievements() override { return NewObject<UIOSAchievements>(); }

	// Создаем коннектор для чата
	virtual UBaseChat* GetChat() override { return NewObject<UIOSChat>(); }

	// Создаем конектор для топа игроков
	virtual UBaseTop* GetTop() override { return NewObject<UIOSTop>(); }
};
