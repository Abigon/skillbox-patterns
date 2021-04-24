// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PrototypeItem.generated.h"


UENUM(Blueprinttype)
enum class EItemTypes : uint8
{
	EIT_SmallHealthPoiton = 0,
	EIT_GreatHealthPoiton,
	EIT_LightItem,
	EIT_MAX
};

UCLASS()
class SKILLBOXPATTERNS_API UPrototypeItem : public UObject
{
	GENERATED_BODY()
	
public:
	UPrototypeItem() {};

	//UPrototypeItem(UPrototypeItem* PrototypeItem)
	//{
	//	UPrototypeItem* NewItem = NewObject<UPrototypeItem>();
	//}

	virtual void SetName(const FString NewName) { ItemName = NewName; }

	FString GetName() const { return ItemName; };
	virtual UPrototypeItem* Clone() const { return nullptr; }
	virtual void PrintItem() {};

protected:
	// Название предмета
	FString ItemName;
};
