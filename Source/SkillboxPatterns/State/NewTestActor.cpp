// Fill out your copyright notice in the Description page of Project Settings.


#include "NewTestActor.h"

void ANewTestActor::SetCurrentState(bool bIsOverlapped)
{
	Super::SetCurrentState(bIsOverlapped);

	// �������� � ����������� ������� �����������
	OnChangeState.Broadcast();
}
