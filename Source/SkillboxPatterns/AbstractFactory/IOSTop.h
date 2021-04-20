// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTop.h"
#include "IOSTop.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UIOSTop : public UBaseTop
{
	GENERATED_BODY()
	
public:
	virtual bool AddToTop(int32 Points) override
	{
		UE_LOG(LogTemp, Warning, TEXT("iOS Add To Top: %i"), Points);
		return true;
	}
};
