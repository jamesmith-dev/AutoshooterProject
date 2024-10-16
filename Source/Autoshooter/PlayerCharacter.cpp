// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"

// Sets the default values for this character's properties
APlayerCharacter::APlayerCharacter()
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	checkf(CameraComponent, TEXT("Failed to create Camera"));

	CameraComponent->SetupAttachment(RootComponent);

	CameraComponent->SetRelativeLocationAndRotation(FVector(1167.f, 0.f, 1032.f), FRotator(-CameraAngle, 180.f, 0.f));

	GetSprite()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, 0.f), FRotator(0.f, -90.f, -CameraAngle));
	GetSprite()->SetRelativeScale3D(FVector(4));
}

// Moves the player given some vector delta
void APlayerCharacter::Move(FVector2D delta)
{
	FVector newLocation = GetActorLocation();

	delta.Normalize();

	Velocity.X = delta.X * MovementSpeed * DeltaTime * 1000.f;
	Velocity.Y = delta.Y * MovementSpeed * DeltaTime * 1000.f;

	newLocation.X += Velocity.Y;
	newLocation.Y += Velocity.X;

	SetActorLocation(newLocation);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* playerInputComponent)
{
	Super::SetupPlayerInputComponent(playerInputComponent);
}

// Called every frame
void APlayerCharacter::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	DeltaTime = deltaTime;

	Running = Velocity != FVector(0, 0, 0);

	// Flip the sprite based on the direction we are moving
	if (Velocity.X < 0)
	{
		GetSprite()->SetRelativeRotation(FRotator(0, -270.f, CameraAngle));
	}

	if (Velocity.X > 0)
	{
		GetSprite()->SetRelativeRotation(FRotator(0, -90.f, -CameraAngle));
	}

	// Set the correct sprite based on our state
	if (Running)
	{
		GetSprite()->SetFlipbook(RunningFlipbook);
	}
	else
	{
		GetSprite()->SetFlipbook(IdleFlipbook);
	}

	Velocity = FVector(0, 0, 0);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}
