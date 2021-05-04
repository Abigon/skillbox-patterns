// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "NormalState.generated.h"

// Состояние свободной сферы

UCLASS()
class SKILLBOXPATTERNS_API UNormalState : public UState
{
	GENERATED_BODY()
	
public:

	virtual FColor GetShpereColor() override { return FColor::Green; }

	virtual void ChangeState() override 
	{
		if (OwnerActor->IsCollisionSphereOverlapped())
		{
			OwnerActor->SetCurrentState(true);
			UE_LOG(LogTemp, Warning, TEXT("Sphere is Overlapped!!"));
		}
	}
};
