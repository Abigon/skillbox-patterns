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


// Структурные паттерны


UCLASS()
class SKILLBOXPATTERNS_API UStructuralPatterns : public UObject
{
	GENERATED_BODY()
	
public:
	void InitStructuralPatterns()
	{
		// Компоновщик и Мост
		InitSquadUnitsBridgeAndVisitor();

		// Фасад
		InitBowArrows();

		// Заместитель
		InitBowArrowsLog();

		// Адаптер
		InitBowWeapon();
	}

	void InitBowWeapon()
	{
		UE_LOG(LogTemp, Warning, TEXT("----  Adapter ----"));

		// Создаем солдата и добавляем ему лук 
		auto Soldier1 = NewObject<USoldier>();
		Soldier1->AddWeapon(NewObject<UBowWeapon>());

		//Отправляем из к точке для вывода лога
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

		// Создаем солдат и добавляем им оружие
		auto Soldier1 = NewObject<USoldier>();
		Soldier1->AddWeapon(NewObject<URifle>());
		auto Soldier2 = NewObject<USoldier>();
		Soldier2->AddWeapon(NewObject<URocketLauncher>());
		auto Soldier3 = NewObject<USoldier>();
		Soldier3->AddWeapon(NewObject<URifle>());

		// Создаем отряд, оружие не добавляем
		auto Squad = NewObject<USquad>();

		// Добавляет жвух солдат в отряд, один остается свободным
		Squad->AddUnit(Soldier1);
		Squad->AddUnit(Soldier2);

		// Отправляем свободного солдата к точке
		Soldier3->MoveToPoint(FVector(1));

		//Отправляем отряд к точке
		Squad->MoveToPoint(FVector(10));

		//Отправляем солдата из отряда к точке
		Soldier1->MoveToPoint(FVector(33));
		
		UE_LOG(LogTemp, Warning, TEXT("   "));


		// Реализация посетителя
		UE_LOG(LogTemp, Warning, TEXT("---- Visitor ----"));

		auto Visitor = NewObject<UHealVisitor>();

		Soldier1->Accept(Visitor);
		Squad->Accept(Visitor);
		//Visitor->VisitSoldier(Soldier1);
		//Visitor->VisitSquad(Squad);

		UE_LOG(LogTemp, Warning, TEXT("   "));
	}
};
