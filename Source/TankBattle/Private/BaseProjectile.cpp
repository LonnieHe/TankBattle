// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"

#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BulletComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletComp"));
	SetRootComponent(BulletComp);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovementComp->InitialSpeed = 1100.f;
	ProjectileMovementComp->MaxSpeed = 1100.f;

}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	BulletComp->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* MyOwner = GetOwner();
	if (MyOwner && OtherActor && OtherActor != this)
	{
		// Apply Damage On Hited Actor
		UGameplayStatics::ApplyDamage(OtherActor,Damage,MyOwner->GetInstigatorController(),GetOwner(),UDamageType::StaticClass());
		// UE_LOG(LogTemp, Warning, TEXT("OtherActor is %s"),*OtherActor->GetName());
	}
	Destroy();
}

