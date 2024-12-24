// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatswordWeapon.h"
#include "GreatswordProjectile.h"

UGreatswordWeapon::UGreatswordWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("Greatsword Constructor"));
}

void UGreatswordWeapon::Initialize(UWorld* world, FVector position)
{
	Super::Initialize(world, position);

	if (World && ProjectileToSpawn)
	{
		FActorSpawnParameters spawnParams;

		Projectile = World->SpawnActor<AProjectileBase>(
			ProjectileToSpawn,
			Position,
			FRotator(),
			spawnParams
		);

		if (Projectile)
		{
			UE_LOG(LogTemp, Display, TEXT("Projectile Instance Spawned."));
		}
	}

}

void UGreatswordWeapon::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Greatsword BeginPlay"));
	Super::BeginPlay();

}

void UGreatswordWeapon::WeaponTimer()
{
	UE_LOG(LogTemp, Warning, TEXT("Timer"));
	if (Projectile)
	{
		//Projectile->Show();
		Projectile->ActivateCollision();
		Projectile->ShowAnimation();
		Projectile->PlayAnimation();
	}
}

void UGreatswordWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Projectile->UpdatePosition(Position);
}
