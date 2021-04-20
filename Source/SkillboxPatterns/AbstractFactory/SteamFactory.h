// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseFactory.h"
#include "SteamAchievements.h"
#include "SteamChat.h"
#include "SteamTop.h"
#include "SteamFactory.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API USteamFactory : public UBaseFactory
{
	GENERATED_BODY()
	
public:

	// ������� �������� ��� ������
	virtual UBaseAchievements* GetAchievements() override { return NewObject<USteamAchievements>(); }

	// ������� ��������� ��� ����
	virtual UBaseChat* GetChat() override { return NewObject<USteamChat>(); }

	// ������� �������� ��� ���� �������
	virtual UBaseTop* GetTop() override { return NewObject<USteamTop>(); }
};
