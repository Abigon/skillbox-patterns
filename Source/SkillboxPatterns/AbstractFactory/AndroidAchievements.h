// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAchievements.h"
#include "AndroidAchievements.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UAndroidAchievements : public UBaseAchievements
{
	GENERATED_BODY()
	
public:

	// Отметить выполненную ачивку в интерфесе Andriod
	virtual bool SetAchievmentComplite(FString AchievmentName) override
	{
		UE_LOG(LogTemp, Warning, TEXT("Android Set Achievment: %s"), *AchievmentName);
		return true;
	}
};
