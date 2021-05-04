// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "DrawDebugHelpers.h"
#include "NormalState.h"
#include "OverlappedState.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"


ATestActor::ATestActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	CollisionVolume->SetSphereRadius(Radius);
	RootComponent = CollisionVolume;
}


void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	OverlappedState = NewObject<UOverlappedState>();
	OverlappedState->SetOwnerActor(this);
	NormalState = NewObject<UNormalState>();
	NormalState->SetOwnerActor(this);

	CurrentState = NormalState;
}

void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 16, CurrentState->GetShpereColor());

	CurrentState->ChangeState();
}

bool ATestActor::IsCollisionSphereOverlapped()
{
	return CollisionVolume->IsOverlappingActor(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATestActor::SetCurrentState(bool bIsOverlapped)
{
	if (bIsOverlapped)
	{
		CurrentState = OverlappedState;
	}
	else
	{
		CurrentState = NormalState;
	}
}
