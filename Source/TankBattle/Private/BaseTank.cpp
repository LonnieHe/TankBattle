// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBattle/Public/BaseTank.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagsSettings.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


ABaseTank::ABaseTank()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	// SpringArmComp->SetupAttachment(TurretMesh);
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 600;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

	TankSpeed = 450.f;
	TurretSpeed = 300.f;
}

void ABaseTank::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (DefaultMappingContext)
				{
					Subsystem->AddMappingContext(DefaultMappingContext, 0);
				}
			}
		}
	}

}

void ABaseTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		FHitResult HitResult;
		PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
		//
		// DrawDebugSphere(GetWorld(),HitResult.ImpactPoint,20.f,8,FColor::Red);

		RotateTurret(HitResult.ImpactPoint);
	}
}

void ABaseTank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABaseTank::MoveInput);
		EIC->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ABaseTank::TurnInput);
		EIC->BindAction(FireAction, ETriggerEvent::Started, this, &ABasePawn::Fire);
	}
}

void ABaseTank::MoveInput(const FInputActionValue& MoveValue)
{
	float InputValue = MoveValue.Get<float>();
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = InputValue * TankSpeed * GetWorld()->GetDeltaSeconds();
	// DeltaLocation.X = InputValue * 100 * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	AddActorLocalOffset(DeltaLocation,true);
}

void ABaseTank::TurnInput(const struct FInputActionValue& MoveValue)
{
	float InputValue = MoveValue.Get<float>();
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw = InputValue * TurretSpeed * GetWorld()->GetDeltaSeconds();
	AddActorLocalRotation(DeltaRotation,true);
}

void ABaseTank::FireInput()
{
	Fire();
}
