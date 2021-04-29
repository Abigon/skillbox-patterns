// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemImage.h"
#include "ItemImageFactory.generated.h"

// ������� �����������. ������� "�������" ������� �� ������� � ���������� ������ �� ���. 
// ���� �����-�� ��� ���������� � ���� ������ �� ����� ��������, �� �� � �� ����� ������, �, ��������������, �� ����� �������� ������

UCLASS()
class SKILLBOXPATTERNS_API UItemImageFactory : public UObject
{
	GENERATED_BODY()
	
public:
	UItemImageFactory()
	{
		FlyweightList.Empty();
	}

	// ���������� ������ �� ������. ���� ��� ��� � ����� �������, �� ������� �������, ����� ���������� ������
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
