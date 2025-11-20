// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankBattle/BasePawn.h"
#include "BaseTower.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ABaseTower : public ABasePawn
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	// virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	TObjectPtr<class ABaseTank> Tank;

	UPROPERTY(EditAnywhere)
	float FireRange = 300.f;

	UPROPERTY(EditAnywhere)
	float FireTimer = 2.f;

	void CheckFireCondition();
	inline bool IsFireRange();
};
