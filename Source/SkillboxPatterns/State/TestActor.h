// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"


UCLASS()
class SKILLBOXPATTERNS_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class USphereComponent* CollisionVolume;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Collision")
	float Radius = 100.f;

	// ���������� true, ���� ����� ����������� �����
	bool IsCollisionSphereOverlapped();

	// ������������ ������� ���������. �.�. ��������� 2 ������������ bool, 
	// ��� ������� ���-�� ��������� ����� ������������ ������������
	virtual void SetCurrentState(bool bIsOverlapped);

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
