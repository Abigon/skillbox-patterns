// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestActor.h"
#include "NewTestActor.generated.h"


// Расширенный класс от TestActor используя Шаблонный метод

DECLARE_MULTICAST_DELEGATE(FOnChangeStateSignature);


UCLASS()
class SKILLBOXPATTERNS_API ANewTestActor : public ATestActor
{
	GENERATED_BODY()
	
public:
	
	FOnChangeStateSignature OnChangeState;

	// Переопределяем метод для сообщения подписчикам о событии
	virtual void SetCurrentState(bool bIsOverlapped) override;
};
