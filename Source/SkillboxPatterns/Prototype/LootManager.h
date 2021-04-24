// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealthPoitonItem.h"
#include "LightItem.h"
#include "LootManager.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API ULootManager : public UObject
{
	GENERATED_BODY()
	
public:
	ULootManager()
	{
		LootItems.Empty();

		// ������� ����� �����
		auto SmallPoiton = NewObject<UHealthPoitonItem>();
		SmallPoiton->SetName("Small Health Poiton");
		SmallPoiton->SetValue(50.f);
		LootItems.Add(EItemTypes::EIT_SmallHealthPoiton, SmallPoiton);

		// ������� ������� �����
		auto BigPoiton = NewObject<UHealthPoitonItem>();
		BigPoiton->SetName("Great Health Poiton");
		BigPoiton->SetValue(150.f);
		LootItems.Add(EItemTypes::EIT_GreatHealthPoiton, BigPoiton);

		// ������� ��������
		auto LightItem = NewObject<ULightItem>();
		LightItem->SetName("Light Point");
		LightItem->SetLightParams(150.f, 200.f);
		LootItems.Add(EItemTypes::EIT_LightItem, LightItem);
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

	// ��������� �������� ����
	TMap<EItemTypes, UPrototypeItem*> LootItems;
};
