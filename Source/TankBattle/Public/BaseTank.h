// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankBattle/BasePawn.h"
#include "BaseTank.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ABaseTank : public ABasePawn
{
	GENERATED_BODY()
public:
	ABaseTank();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class USpringArmComponent> SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UCameraComponent> CameraComp;
};
