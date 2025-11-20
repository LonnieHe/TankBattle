// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTower.h"
#include "BaseTank.h"

void ABaseTower::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABaseTower::CheckFireCondition, 2.f, true, 2.f);
}

void ABaseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Tank)
	{
		float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());
		if (Distance <= FireRange)
		{
			RotateTurret(Tank->GetActorLocation());
		}
	}
	
}

void ABaseTower::CheckFireCondition()
{
	if (Tank)
	{
		float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());
		if (Distance <= FireRange)
		{
			Fire();
		}
	}
	
}
