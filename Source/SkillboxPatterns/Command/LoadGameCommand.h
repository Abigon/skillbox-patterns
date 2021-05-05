// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "../SkillboxPatternsGameMode.h"
#include "LoadGameCommand.generated.h"

// ���������� ������� �������� ����

UCLASS()
class SKILLBOXPATTERNS_API ULoadGameCommand : public UCommand
{
	GENERATED_BODY()
	
public:

	// ��������� �������, ��������� ������ ����������
	virtual void Execute() override
	{
		if (Receiver)
		{
			Receiver->LoadGame();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("You must set Receiver for LoadGameCommand!!!"));
		}
	}

	// ������������� ����������
	void SetReceiver(ASkillboxPatternsGameMode* NewReceiver)
	{
		Receiver = NewReceiver;
	}

private:
	ASkillboxPatternsGameMode* Receiver = nullptr;

};
