// Fill out your copyright notice in the Description page of Project Settings.


#include "HeathComponent.h"

#include "TankBattleGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
UHealthComponent::UHealthComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::OnDamageTaken);

	AGameModeBase* GameMode = UGameplayStatics::GetGameMode(GetWorld());
	if (GameMode)
	{
		TankBattleGameMode = Cast<ATankBattleGameMode>(GameMode);
	}
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunciton)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunciton);
}

void UHealthComponent::OnDamageTaken(AActor* DamagedActor, float Damage,
	const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage > 0)
	{
		CurrentHealth -= Damage;
		if (CurrentHealth <= 0)
		{
			if (TankBattleGameMode)
			{
				TankBattleGameMode->ActorDied(GetOwner());
			}
		}
	}
}


