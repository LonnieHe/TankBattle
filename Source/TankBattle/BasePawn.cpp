// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"

#include "Components/CapsuleComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	BulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnPoint"));
	BulletSpawnPoint->SetupAttachment(TurretMesh);
}

void ABasePawn::RotateTurret(FVector TargetLocation)
{
	TargetLocation -= TurretMesh->GetComponentLocation();
	// Direction.Normalize();
	// Direction.Rotation().Yaw;

	FRotator LookAtRotation = FRotator(0.f, TargetLocation.Rotation().Yaw, 0.f);
	TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(), LookAtRotation, GetWorld()->GetDeltaSeconds(), 5.f));
	
}

void ABasePawn::Fire()
{
	UE_LOG(LogTemp, Display, TEXT("DoBaseFire"));
	FVector FireLocation = BulletSpawnPoint->GetComponentLocation();
	FRotator FireRotation = BulletSpawnPoint->GetComponentRotation();
	DrawDebugSphere(GetWorld(),FireLocation,10.f,12,FColor::Red,false,3.f);
	DrawDebugLine(GetWorld(),FireLocation,FireLocation + FireRotation.Vector() *400.f,FColor::Blue,false,3.f,0,2.f);
}



