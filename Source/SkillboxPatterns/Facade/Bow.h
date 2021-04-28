// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bow.generated.h"

// ����� ����. 

UCLASS()
class SKILLBOXPATTERNS_API UBow : public UObject
{
	GENERATED_BODY()

public:

	void Equip()			// ����� ���� ��� ������ ����������
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Equip"));
	}

	void Unarm()			// ������ ���� ��� ������ ����������
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Unarm"));
	}

	void PrepareToShot()	// ���������� � �������� (����������� ������)
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Prepare To Shot"));
	}

	void Shot() 			// ������� 
	{
		UE_LOG(LogTemp, Warning, TEXT("Bow Shot"));
	}
};
