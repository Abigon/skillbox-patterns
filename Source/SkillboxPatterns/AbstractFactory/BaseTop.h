// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseTop.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API UBaseTop : public UObject
{
	GENERATED_BODY()
	
public:

	// Обновить положение игрока в общем топе 
	virtual bool AddToTop(int32 Points) { return false; }
};
