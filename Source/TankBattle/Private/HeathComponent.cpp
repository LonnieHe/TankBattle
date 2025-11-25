// Fill out your copyright notice in the Description page of Project Settings.


#include "HeathComponent.h"

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
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunciton)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunciton);
}


