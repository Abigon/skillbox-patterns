// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseChat.h"
#include "SteamChat.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API USteamChat : public UBaseChat
{
	GENERATED_BODY()
	
public:
	virtual bool ConnectToChat() override
	{
		UE_LOG(LogTemp, Warning, TEXT("Steam Chat Connected..."));
		return true;
	}

	virtual bool SendMessage(FString MessageString) override
	{
		UE_LOG(LogTemp, Warning, TEXT("Steam Send Message: %s"), *MessageString);
		return true;
	}
};
