// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordsmanClass.h"
#include "GreatswordWeapon.h"

ASwordsmanClass::ASwordsmanClass()
{
}

void ASwordsmanClass::BeginPlay()
{
	Super::BeginPlay();

	UWorld* world = GetWorld();
	if (world)
	{
		UE_LOG(LogTemp, Warning, TEXT("WORLD."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO WORLD."));
	}

	Weapon = NewObject<UWeaponBase>(this, WeaponClass);
	Weapon->RegisterComponent();
	Weapon->Initialize(world, GetActorLocation());
	//Weapon->Fire();

}




