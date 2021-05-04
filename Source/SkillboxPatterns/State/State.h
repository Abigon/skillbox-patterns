// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestActor.h"
#include "State.generated.h"

// Интерфейс состояния

UCLASS()
class SKILLBOXPATTERNS_API UState : public UObject
{
	GENERATED_BODY()

public:
	void SetOwnerActor(ATestActor* NewActor) { OwnerActor = NewActor; }

	virtual void ChangeState() {};

	virtual FColor GetShpereColor() { return FColor::White; }

protected:
	ATestActor* OwnerActor = nullptr;
	
};
