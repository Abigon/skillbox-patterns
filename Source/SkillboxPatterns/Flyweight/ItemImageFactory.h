// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemImage.h"
#include "ItemImageFactory.generated.h"

// Фабрика тяжеловесов. Создает "тяжелые" объекты по запросу и вызвращает ссылки на них. 
// Если какой-то тип тяжеловеса в ходе сессия не будет запрошен, то он и не будет создан, и, соответственно, не будет занимать память

UCLASS()
class SKILLBOXPATTERNS_API UItemImageFactory : public UObject
{
	GENERATED_BODY()
	
public:
	UItemImageFactory()
	{
		FlyweightList.Empty();
	}

	// Возвращаем ссылку на объект. Если его нет в нашем массиве, то сначала сохдаем, потом возвращаем ссылку
	UItemImage* GetImageByType(ETypeOfImage ImageType) 
	{
		if (!FlyweightList.Contains(ImageType))
		{
			auto NewImage = NewObject<UItemImage>();
			NewImage->SetImageType(ImageType);

			FlyweightList.Add(ImageType, NewImage);
			UE_LOG(LogTemp, Warning, TEXT("New ImageItem: %i"), FlyweightList.Num());
		}

		return FlyweightList[ImageType];
	}

private:
	TMap<ETypeOfImage, UItemImage*> FlyweightList;
};
