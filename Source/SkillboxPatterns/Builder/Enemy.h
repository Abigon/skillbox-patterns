// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Enemy.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UEnemy : public UObject
{
	GENERATED_BODY()
	
public:
	TArray<FString> EnemyParts;

	void ListEnemyParts()
	{
		FString ResutString = "";
		for (auto EnemyPart : EnemyParts)
		{
			ResutString = ResutString + EnemyPart + " / ";
		}

		UE_LOG(LogTemp, Warning, TEXT("Result Enemy - %s"), *ResutString);
	}
};
