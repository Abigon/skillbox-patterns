// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bow.h"
#include "Arrow.generated.h"


// ����� ������. ���������, ��� ��������� ��������� � �������� ������ �������� � ������ �������� ����� ���������

UCLASS()
class SKILLBOXPATTERNS_API UArrow : public UObject
{
	GENERATED_BODY()

public:

	~UArrow()
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrow delete"));
	}

	void MoveTo(FVector Point)		// �������� ������ ����� �������� � �����
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrow Move To : %s"), *Point.ToString());
	}	

	void Arming(UBow* Bow)			// ������������� ������ � ���� ��� ��������� ������
	{
		UE_LOG(LogTemp, Warning, TEXT("Arrow Arming"));
	}
};
