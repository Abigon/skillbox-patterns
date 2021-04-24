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

private:
	static USingletonConnector* Instance;
};

inline USingletonConnector* USingletonConnector::Get(FString Name)
{
	if (!Instance)
	{
		Instance = NewObject<USingletonConnector>();
		UE_LOG(LogTemp, Warning, TEXT("Init from: %s"), *Name);
	}
	return Instance;
}
