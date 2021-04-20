// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAchievements.h"
#include "SteamAchievements.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API USteamAchievements : public UBaseAchievements
{
	GENERATED_BODY()
	
public:

	// Отметить выполненную ачивку в интерфесе Steam
	virtual bool SetAchievmentComplite(FString AchievmentName) override
	{
		UE_LOG(LogTemp, Warning, TEXT("Steam Set Achievment: %s"), *AchievmentName);
		return true;
	}
};
