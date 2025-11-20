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
	if (IsFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
	
}

void ABaseTower::CheckFireCondition()
{
	if (IsFireRange())
	{
		Fire();
	}
}

bool ABaseTower::IsFireRange()
{
	return (Tank
		&& 	FVector::Dist(Tank->GetActorLocation(), GetActorLocation()) <= FireRange
	);
}
