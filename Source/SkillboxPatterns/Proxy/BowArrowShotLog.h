// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Facade/BowArrowShot.h"
#include "BowArrowShotLog.generated.h"


// ����� �����������. ��������� ����������� ������������� ����� UBowArrowShot. 
// ��� ����������� ������ ��������� ���, ��� ����� ������� ��������� � ���� � �.�.

UCLASS()
class SKILLBOXPATTERNS_API UBowArrowShotLog : public UObject
{
	GENERATED_BODY()
	
public:
	UBowArrowShotLog()
	{
		LogStrings.Empty();

		BowArrowShot = NewObject<UBowArrowShot>();				// ������� �����, ������� ��������
		if (BowArrowShot)
		{
			LogStrings.Add("Init Object");						// �������� �������������
		}
		else
		{
			LogStrings.Add("Object Initialization Error");		// �������� ������ �������������
		}
	}

	~UBowArrowShotLog()
	{
		// ��� ����������� ������� ���
		UE_LOG(LogTemp, Warning, TEXT("---- Proxy 2 ----"));
		
		for (auto LogString : LogStrings)
		{
			UE_LOG(LogTemp, Warning, TEXT("UBowArrowShotLog: %s"), *LogString);
		}

		UE_LOG(LogTemp, Warning, TEXT("  "));
	}

	// �������
	void Shot()
	{
		if (BowArrowShot)
		{
			BowArrowShot->Shot();		
			LogStrings.Add("Shot");				
		}
		else
		{
			LogStrings.Add("Shot Error");		
		}
	}

	// ������ ���
	void Hide()
	{
		if (BowArrowShot)
		{
			BowArrowShot->Hide();						
			LogStrings.Add("Bow Hide");
		}
		else
		{
			LogStrings.Add("Hide Error");
		}
	}

private:
	UBowArrowShot* BowArrowShot = nullptr;
	TArray<FString> LogStrings;
};
