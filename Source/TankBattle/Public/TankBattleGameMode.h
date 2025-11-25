// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankBattleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankBattleGameMode : public AGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	TObjectPtr<class ABaseTank> Tank;
	int32 TowerCount;

	void ActorDied(AActor* DeadActor);
};
