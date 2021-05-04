// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Composite/Squad.h"
#include "Composite/Soldier.h"
#include "Bridge/Rifle.h"
#include "Bridge/RocketLauncher.h"
#include "Facade/BowArrowShot.h"
#include "Proxy/BowArrowShotLog.h"
#include "Adapter/BowWeapon.h"
#include "Visitor/HealVisitor.h"
#include "StructuralPatterns.generated.h"


// ����������� ��������


UCLASS()
class SKILLBOXPATTERNS_API UStructuralPatterns : public UObject
{
	GENERATED_BODY()
	
public:
	void InitStructuralPatterns()
	{
		// ����������� � ����
		InitSquadUnitsBridgeAndVisitor();

		// �����
		InitBowArrows();

		// �����������
		InitBowArrowsLog();

		// �������
		InitBowWeapon();
	}

	void InitBowWeapon()
	{
		UE_LOG(LogTemp, Warning, TEXT("----  Adapter ----"));

		// ������� ������� � ��������� ��� ��� 
		auto Soldier1 = NewObject<USoldier>();
		Soldier1->AddWeapon(NewObject<UBowWeapon>());

		//���������� �� � ����� ��� ������ ����
		Soldier1->MoveToPoint(FVector(33));

		UE_LOG(LogTemp, Warning, TEXT("   "));
	}

	void InitBowArrowsLog()
	{
		UE_LOG(LogTemp, Warning, TEXT("---- Proxy 1 ----"));

		auto BALog = NewObject<UBowArrowShotLog>();
		BALog->Shot();
		BALog->Hide();

		UE_LOG(LogTemp, Warning, TEXT("   "));
	}

	void InitBowArrows()
	{
		UE_LOG(LogTemp, Warning, TEXT("---- Facade ----"));

		auto BA = NewObject<UBowArrowShot>();
		BA->Shot();
		BA->Hide();

		UE_LOG(LogTemp, Warning, TEXT("   "));
	}

	void InitSquadUnitsBridgeAndVisitor()
	{
		UE_LOG(LogTemp, Warning, TEXT("----  Composite & Bridge ----"));

		// ������� ������ � ��������� �� ������
		auto Soldier1 = NewObject<USoldier>();
		Soldier1->AddWeapon(NewObject<URifle>());
		auto Soldier2 = NewObject<USoldier>();
		Soldier2->AddWeapon(NewObject<URocketLauncher>());
		auto Soldier3 = NewObject<USoldier>();
		Soldier3->AddWeapon(NewObject<URifle>());

		// ������� �����, ������ �� ���������
		auto Squad = NewObject<USquad>();

		// ��������� ���� ������ � �����, ���� �������� ���������
		Squad->AddUnit(Soldier1);
		Squad->AddUnit(Soldier2);

		// ���������� ���������� ������� � �����
		Soldier3->MoveToPoint(FVector(1));

		//���������� ����� � �����
		Squad->MoveToPoint(FVector(10));

		//���������� ������� �� ������ � �����
		Soldier1->MoveToPoint(FVector(33));
		
		UE_LOG(LogTemp, Warning, TEXT("   "));


		// ���������� ����������
		UE_LOG(LogTemp, Warning, TEXT("---- Visitor ----"));

		auto Visitor = NewObject<UHealVisitor>();

		Soldier1->Accept(Visitor);
		Squad->Accept(Visitor);
		//Visitor->VisitSoldier(Soldier1);
		//Visitor->VisitSquad(Squad);

		UE_LOG(LogTemp, Warning, TEXT("   "));
	}
};
