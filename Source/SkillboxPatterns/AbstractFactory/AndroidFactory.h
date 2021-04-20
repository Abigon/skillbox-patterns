// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseFactory.h"
#include "AndroidAchievements.h"
#include "AndroidChat.h"
#include "AndroidTop.h"
#include "UObject/UObjectGlobals.h"
#include "AndroidFactory.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UAndroidFactory : public UBaseFactory
{
	GENERATED_BODY()
	
public:

	// ������� �������� ��� ������
	virtual UAndroidAchievements* GetAchievements() override { return NewObject<UAndroidAchievements>(); }

	// ������� ��������� ��� ����
	virtual UAndroidChat* GetChat() override { return NewObject<UAndroidChat>(); }

	// ������� �������� ��� ���� �������
	virtual UAndroidTop* GetTop() override { return NewObject<UAndroidTop>(); }
};
