// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Command.generated.h"

// ����� ��� ���� ���������� ������ ���������

UCLASS()
class SKILLBOXPATTERNS_API UCommand : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void Execute() {};


};
