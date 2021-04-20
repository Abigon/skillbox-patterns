// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseAchievements.h"
#include "BaseChat.h"
#include "BaseTop.h"
#include "BaseFactory.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UBaseFactory : public UObject
{
	GENERATED_BODY()

public:
	
	// ������� ��������� ��� ������
	virtual UBaseAchievements* GetAchievements() { return nullptr; }

	// ������� ��������� ��� ����
	virtual UBaseChat* GetChat() { return nullptr; }

	// ������� ��������� ��� ���� �������
	virtual UBaseTop* GetTop() { return nullptr; }
};
