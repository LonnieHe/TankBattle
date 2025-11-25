// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBattleGameMode.h"

#include "BaseTank.h"
#include "TankBattle/Public/BaseTower.h"
#include "Kismet/GameplayStatics.h"

inline void ATankBattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> TowerActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseTower::StaticClass(),TowerActors);
	TowerCount = TowerActors.Num();
	UE_LOG(LogTemp, Warning, TEXT("TowerCount: %d"), TowerCount);

	if (Tank = Cast<ABaseTank>(UGameplayStatics::GetPlayerPawn(GetWorld(),0)))
	{
		for (AActor* Actor : TowerActors)
		{
			if (ABaseTower* Tower = Cast<ABaseTower>(Actor))
			{
				Tower->Tank = Tank;
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank is NULL"));
	}
}

void ATankBattleGameMode::ActorDied(AActor* DeadActor)
{
	// if (ABaseTank* DeadTank = Cast<ABaseTank>(DeadActor))
	if (DeadActor == Tank)
	{
		
	}
	else if (ABaseTower* DeadTower = Cast<ABaseTower>(DeadActor))
	{
		DeadTower->Destroy();
		if (--TowerCount == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Win"));
		}
	}
}
