// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrototypeItem.h"
#include "HealthPoitonItem.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UHealthPoitonItem : public UPrototypeItem
{
	GENERATED_BODY()
	
public:

	virtual UHealthPoitonItem* Clone() const override 
	{
		auto NewItem = NewObject<UHealthPoitonItem>();
		if (NewItem)
		{
			NewItem->ItemName = ItemName;
			NewItem->ItemValue = ItemValue;
		}
		return NewItem;
	};

	virtual void PrintItem() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Item: %s, Value: %f"), *ItemName, ItemValue);
	};

	void SetValue(float NewValue) { ItemValue = NewValue; }

protected:
	// Объем жидкости 
	float ItemValue;
};
