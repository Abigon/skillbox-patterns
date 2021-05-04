// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"



DECLARE_MULTICAST_DELEGATE(FOnChangeStateSignature);

UCLASS()
class SKILLBOXPATTERNS_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class USphereComponent* CollisionVolume;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	float Radius = 100.f;

	FOnChangeStateSignature OnChangeState;

	// ¬озвращает true, если игрок перекрывает сферу
	bool IsCollisionSphereOverlapped();

	// ”стнавливает текущее состо€ние. “.к. состо€ний 2 используетс€ bool, 
	// при большем кол-ве состо€ний можно использовать перечислени€
	void SetCurrentState(bool bIsOverlapped);

protected:
	UPROPERTY()
	class UState* CurrentState = nullptr;
	UPROPERTY()
	class UOverlappedState* OverlappedState = nullptr;
	UPROPERTY()
	class UNormalState* NormalState = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
