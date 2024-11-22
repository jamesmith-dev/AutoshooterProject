// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
	//SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collsion Sphere"));
	//SphereCollisionComponent->SetHiddenInGame(false);
	//RootComponent = SphereCollisionComponent;

	//FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	//FlipbookComponent->SetupAttachment(SphereCollisionComponent);
	//FlipbookComponent->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	//FlipbookComponent->SetLooping(false);
	

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	if (Sprite && FlipbookComponent)
	{
		FlipbookComponent->SetFlipbook(Sprite);
	}
	
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectileBase::PlayAnimation()
{
	if (FlipbookComponent)
	{
		FlipbookComponent->PlayFromStart();
	}
}

void AProjectileBase::Show()
{
	SetActorHiddenInGame(false);
	IsActive = true;
}

void AProjectileBase::ShowAnimation()
{
	// Implement in child class
}

void AProjectileBase::HideAnimation()
{
	// Implement in child class
}

void AProjectileBase::ActivateCollision()
{
	// Implement in child class
}

void AProjectileBase::DisableCollision()
{
	// Implement in child class
}

void AProjectileBase::Hide()
{
	UE_LOG(LogTemp, Warning, TEXT("Hiding"));
	SetActorHiddenInGame(true);
	IsActive = false;
}

bool AProjectileBase::GetIsActive()
{
	return IsActive;
}


void AProjectileBase::UpdatePosition(FVector newPos)
{
	SetActorLocation(newPos);
}

void AProjectileBase::UpdateRotation(FRotator newRotation)
{

}


