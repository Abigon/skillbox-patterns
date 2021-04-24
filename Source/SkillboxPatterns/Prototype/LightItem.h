// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrototypeItem.h"
#include "LightItem.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API ULightItem : public UPrototypeItem
{
	GENERATED_BODY()

public:

	virtual ULightItem* Clone() const override
	{
		auto NewItem = NewObject<ULightItem>();
		if (NewItem)
		{
			NewItem->ItemName = ItemName;
			NewItem->LightPower = LightPower;
			NewItem->LightDistance = LightDistance;
		}
		return NewItem;
	};

	virtual void PrintItem() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Item: %s, Power: %f, Distance: %f"), *ItemName, LightPower, LightDistance);
	};

	void SetLightParams(float NewPower, float NewDistance) 
	{
		LightPower = NewPower;  
		LightDistance = NewDistance;
	}

protected:
	// Дальность свечения 
	float LightDistance;

	// Мощность свечения 
	float LightPower;
};
