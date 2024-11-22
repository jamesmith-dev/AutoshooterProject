// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponBase.h"
#include "Swordsman/GreatswordProjectile.h"

// Sets default values for this component's properties
UWeaponBase::UWeaponBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UWeaponBase::Initialize(UWorld* world, FVector position)
{
	World = world;
	Position = position;

	World->GetTimerManager().SetTimer(
		WeaponTimerHandle,
		this,
		&UWeaponBase::WeaponTimer,
		4.0f,
		true
	);

}

AProjectileBase* UWeaponBase::Fire()
{
	FActorSpawnParameters spawnParams;

	if (!World)
	{
		UE_LOG(LogTemp, Warning, TEXT("World NULL."));
	}

	if (!ProjectileToSpawn)
	{
		UE_LOG(LogTemp, Display, TEXT("Projectile NULL."));
	}

	if (World && ProjectileToSpawn)
	{
		Projectile = World->SpawnActor<AProjectileBase>(
			ProjectileToSpawn,
			Position, 
			FRotator(), 
			spawnParams
		);

		if (Projectile)
		{
			UE_LOG(LogTemp, Display, TEXT("Projectile Instance Spawned."));
			return Projectile;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Projectile Instance Failed To Spawned."));
		}
	}
	else
	{
			UE_LOG(LogTemp, Warning, TEXT("Failed to Fire Weapon."));
	}
	return nullptr;
}

void UWeaponBase::SetWorld(UWorld* world)
{
	World = world;
}

void UWeaponBase::SetPosition(FVector position)
{
	Position = position;
}

// Called when the game starts
void UWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

void UWeaponBase::WeaponTimer()
{
	UE_LOG(LogTemp, Warning, TEXT("Timer"));
}

void UWeaponBase::InitializeComponent()
{
	//UActorComponent::InitializeComponent();

	UE_LOG(LogTemp, Warning, TEXT("WeaponBase InitializeComponent."));
}

// Called every frame
void UWeaponBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
