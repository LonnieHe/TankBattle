// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBattle/Public/BaseTank.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


ABaseTank::ABaseTank()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	// SpringArmComp->SetupAttachment(TurretMesh);
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 600;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp); 
}

void ABaseTank::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseTank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
