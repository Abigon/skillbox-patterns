// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SingletonConnector.generated.h"


UCLASS()
class USingletonConnector : public UObject
{
	GENERATED_BODY()

public:
	static USingletonConnector* Get(FString Name);

	// Переопределяем деструктор для проверки удаления обхекта
	~USingletonConnector()
	{
		UE_LOG(LogTemp, Warning, TEXT("Delete USingletonConnector"));
	}

protected:
	// Прячем конструктор
	USingletonConnector() {};

private:
	static USingletonConnector* Instance;
};

USingletonConnector* USingletonConnector::Instance = nullptr;


inline USingletonConnector* USingletonConnector::Get(FString Name)
{
	UE_LOG(LogTemp, Warning, TEXT("----  Singleton  ----"));

	if (!Instance)
	{
		Instance = NewObject<USingletonConnector>();
		UE_LOG(LogTemp, Warning, TEXT("Init from: %s"), *Name);
	}

	UE_LOG(LogTemp, Warning, TEXT("Call from: %s"), *Name);
	UE_LOG(LogTemp, Warning, TEXT(" "));
	return Instance;
}
