// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemImage.generated.h"


// Класс Легковес, хотя на самом деле Тяжеловес, т.к. в нем содержится самая тяжелая неуникальная часть конечных экземпляров объектов


UENUM(Blueprinttype)
enum class ETypeOfImage : uint8
{
	ETO_HealthPoiton = 0,
	ETO_LightItem,
	ETO_MAX
};


UCLASS()
class SKILLBOXPATTERNS_API UItemImage : public UObject
{
	GENERATED_BODY()

public:

	void SetImageType(ETypeOfImage NewType)
	{
		// Устанавливаем имя для теста
		switch (NewType)
		{
		case ETypeOfImage::ETO_HealthPoiton: ImageName += "Health Poiton Image"; break;
		case ETypeOfImage::ETO_LightItem: ImageName += "Light Image"; break;
		default: ;
		}
		
		// Загрузка картинки
	}

	FString GetImageName() const { return ImageName; }

	void DrawImage(FVector2D Point)
	{
		// Отрисовываем текущюю картинку в заданных координатах
	}


private:
	FString ImageName = "";
};
