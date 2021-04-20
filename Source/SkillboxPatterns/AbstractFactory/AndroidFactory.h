// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseFactory.h"
#include "AndroidAchievements.h"
#include "AndroidChat.h"
#include "AndroidTop.h"
#include "UObject/UObjectGlobals.h"
#include "AndroidFactory.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UAndroidFactory : public UBaseFactory
{
	GENERATED_BODY()
	
public:

	// Создаем конектор для ачивок
	virtual UAndroidAchievements* GetAchievements() override { return NewObject<UAndroidAchievements>(); }

	// Создаем коннектор для чата
	virtual UAndroidChat* GetChat() override { return NewObject<UAndroidChat>(); }

	// Создаем конектор для топа игроков
	virtual UAndroidTop* GetTop() override { return NewObject<UAndroidTop>(); }
};
