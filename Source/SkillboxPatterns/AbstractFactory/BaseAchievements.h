// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseAchievements.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UBaseAchievements : public UObject
{
	GENERATED_BODY()
	
public:

	// Отметить ачивку выполненной
	virtual bool SetAchievmentComplite(FString AchievmentName) { return false; }

};
