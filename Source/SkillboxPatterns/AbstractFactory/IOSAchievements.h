// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAchievements.h"
#include "IOSAchievements.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UIOSAchievements : public UBaseAchievements
{
	GENERATED_BODY()

public:

	// Отметить выполненную ачивку в интерфесе GameCenter iOS
	virtual bool SetAchievmentComplite(FString AchievmentName) override
	{
		UE_LOG(LogTemp, Warning, TEXT("iOS Set Achievment: %s"), *AchievmentName);
		return true;
	}
};
