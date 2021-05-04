// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "State.h"
#include "OverlappedState.generated.h"

// Состояние перекрытой сферы

UCLASS()
class SKILLBOXPATTERNS_API UOverlappedState : public UState
{
	GENERATED_BODY()
	
public:

	virtual FColor GetShpereColor() override { return FColor::Red; }

	virtual void ChangeState() override
	{
		if (!OwnerActor->IsCollisionSphereOverlapped())
		{
			OwnerActor->SetCurrentState(false);
			UE_LOG(LogTemp, Warning, TEXT("Sphere is Empty!!"));
		}
	}

};
