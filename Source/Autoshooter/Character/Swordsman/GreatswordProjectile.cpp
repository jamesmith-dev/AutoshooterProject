// Fill out your copyright notice in the Description page of Project Settings.

#include "GreatswordProjectile.h"

AGreatswordProjectile::AGreatswordProjectile()
	: AProjectileBase()
{
	UE_LOG(LogTemp, Warning, TEXT("GreatswordProjectile Constructor"));

	BoxCollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	BoxCollisionComponent->SetHiddenInGame(false);
	BoxCollisionComponent->SetBoxExtent(FVector(200.f, 100.f, 50.f));
	BoxCollisionComponent->SetRelativeLocationAndRotation(FVector(200.f, 0.f, 0.f), FRotator(0.f, 90.f, 0.f));
	RootComponent = BoxCollisionComponent;

	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	FlipbookComponent->SetupAttachment(BoxCollisionComponent);
	FlipbookComponent->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	FlipbookComponent->SetLooping(false);

}

void AGreatswordProjectile::ShowAnimation()
{
	if (FlipbookComponent)
	{
		FlipbookComponent->SetHiddenInGame(false);
	}
}

void AGreatswordProjectile::HideAnimation()
{
	if (FlipbookComponent)
	{
		FlipbookComponent->SetHiddenInGame(true);
	}
}

void AGreatswordProjectile::ActivateCollision()
{
	if (BoxCollisionComponent)
	{
		BoxCollisionComponent->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndProbe);
		BoxCollisionComponent->SetHiddenInGame(false);
	}
}

void AGreatswordProjectile::DisableCollision()
{
	if (BoxCollisionComponent)
	{
		BoxCollisionComponent->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
		BoxCollisionComponent->SetHiddenInGame(true);
	}
}

void AGreatswordProjectile::Hide()
{
	HideAnimation();
	DisableCollision();
}

void AGreatswordProjectile::BeginPlay()
{
	Super::BeginPlay();

	if (FlipbookComponent)
	{
		UE_LOG(LogTemp, Display, TEXT("Setting Delegate"));
		FlipbookComponent->OnFinishedPlaying.AddDynamic(this, &AGreatswordProjectile::Hide);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error Setting Delegate. Flipbook Component is NULL!"));
	}

	if (BoxCollisionComponent)
	{
		BoxCollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AGreatswordProjectile::OnOverlapBegin);
	}
}

void AGreatswordProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEnemy* enemy = Cast<AEnemy>(OtherActor))
	{
		UE_LOG(LogTemp, Display, TEXT("COLLISION: %s"), *OtherActor->GetName());
	}
}

void AGreatswordProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGreatswordProjectile::UpdatePosition(FVector newPos)
{
	SetActorLocation(FVector(newPos.X + 200.f, newPos.Y, newPos.Z));
}

void AGreatswordProjectile::UpdateRotation(FRotator newRotation)
{
	

}

