// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseChat.generated.h"

UCLASS()
class SKILLBOXPATTERNS_API UBaseChat : public UObject
{
	GENERATED_BODY()

public:

	// ����������� � ����
	virtual bool ConnectToChat() { return false; }

	// ��������� ��������� � ����� ���
	virtual bool SendMessage(FString MessageString) { return false; }
};
