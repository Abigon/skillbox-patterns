// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Flyweight/ItemImage.h"
#include "PrototypeItem.generated.h"


// ��������� ��������� � ������������ "���������� �����" ��� ���������.
// �������� ������ �� ItemImage, ������� �� �������� ������ ��� ����� ������ � �������� ����� ������

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

	// ��������� ��� �������� ��� ����
	FString GetImageName() const
	{
		if (ItemImage) return ItemImage->GetImageName();
		return "";
	}

	virtual UPrototypeItem* Clone() const { return nullptr; }
	virtual void PrintItem() {};

protected:
	// �������� ��������
	FString ItemName;

	// ������ �� �����������
	UItemImage* ItemImage = nullptr;
};
