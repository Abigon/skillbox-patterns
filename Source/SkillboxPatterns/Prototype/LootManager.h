// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealthPoitonItem.h"
#include "LightItem.h"
#include "../Flyweight/ItemImageFactory.h"
#include "LootManager.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API ULootManager : public UObject
{
	GENERATED_BODY()
	
public:
	ULootManager()
	{
		LootItems.Empty();
	}

	void InitLootManager()
	{
		UE_LOG(LogTemp, Warning, TEXT("---- Flyweight ----"));

		auto ItemImageFactory = NewObject<UItemImageFactory>();

		// Создаем малое пойло
		auto SmallPoiton = NewObject<UHealthPoitonItem>();
		SmallPoiton->SetName("Small Health Poiton");
		SmallPoiton->SetValue(50.f);
		SmallPoiton->SetImage(ItemImageFactory->GetImageByType(ETypeOfImage::ETO_HealthPoiton));
		LootItems.Add(EItemTypes::EIT_SmallHealthPoiton, SmallPoiton);

		// Создаем большое пойло
		auto BigPoiton = NewObject<UHealthPoitonItem>();
		BigPoiton->SetName("Great Health Poiton");
		BigPoiton->SetValue(150.f);
		BigPoiton->SetImage(ItemImageFactory->GetImageByType(ETypeOfImage::ETO_HealthPoiton));
		LootItems.Add(EItemTypes::EIT_GreatHealthPoiton, BigPoiton);

		// Создаем лампочку
		auto LightItem = NewObject<ULightItem>();
		LightItem->SetName("Light Point");
		LightItem->SetLightParams(150.f, 200.f);
		LightItem->SetImage(ItemImageFactory->GetImageByType(ETypeOfImage::ETO_LightItem));
		LootItems.Add(EItemTypes::EIT_LightItem, LightItem);

		UE_LOG(LogTemp, Warning, TEXT("  "));
	}

	UPrototypeItem* GetNewLootItem(EItemTypes ItemType)
	{
		if (LootItems.Contains(ItemType))
		{
			return LootItems[ItemType]->Clone();
		}
		return nullptr;
	}

private:

	// Хранилище образцов лута
	TMap<EItemTypes, UPrototypeItem*> LootItems;
};
