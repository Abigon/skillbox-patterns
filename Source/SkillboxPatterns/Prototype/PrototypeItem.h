// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Flyweight/ItemImage.h"
#include "PrototypeItem.generated.h"


// Интерфейс Прототипа и одновременно "уникальная часть" для Легковеса.
// Содержит ссылку на ItemImage, который не уникален только для этого объета и занимает много памяти

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

	virtual void SetName(const FString NewName) { ItemName = NewName; }
	virtual void SetImage(UItemImage* Image) { ItemImage = Image; }

	FString GetName() const { return ItemName; };

	// Возвращам имя картинки для лога
	FString GetImageName() const
	{
		if (ItemImage) return ItemImage->GetImageName();
		return "";
	}

	virtual UPrototypeItem* Clone() const { return nullptr; }
	virtual void PrintItem() {};

protected:
	// Название предмета
	FString ItemName;

	// Ссылка на изображение
	UItemImage* ItemImage = nullptr;
};
