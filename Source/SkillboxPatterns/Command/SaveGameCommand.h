// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "../SkillboxPatternsGameMode.h"
#include "SaveGameCommand.generated.h"


// Реализация команды сохранения игры

UCLASS()
class SKILLBOXPATTERNS_API USaveGameCommand : public UCommand
{
	GENERATED_BODY()
	
public:

	// Выполняем команду, отправляя запрос получателю
	virtual void Execute() override
	{
		if (Receiver)
		{
			Receiver->SaveGame();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("You must set Receiver for SaveGameCommand!!!"));
		}
	}

	// Устанавливаем получателя
	void SetReceiver(ASkillboxPatternsGameMode* NewReceiver) 
	{
		Receiver = NewReceiver;
	}

private:
	ASkillboxPatternsGameMode* Receiver = nullptr;

};
