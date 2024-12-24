// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

// Sets the default values for this character's properties
ACharacterBase::ACharacterBase()
{
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	checkf(CameraComponent, TEXT("Failed to create Camera"));

	CameraComponent->SetupAttachment(RootComponent);

	// Calculate the vertical position of our sprite to position it at the bottom of the capsule
	float capsuleHeight = GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
	float bias = 2.f;
	float spriteVerticalPos = -(capsuleHeight + bias);

	CameraComponent->SetRelativeLocationAndRotation(FVector(1167.f, 0.f, 1032.f), FRotator(-CameraAngle, 180.f, 0.f));

	GetSprite()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, spriteVerticalPos), FRotator(0.f, -90.f, -CameraAngle));
	GetSprite()->SetRelativeScale3D(FVector(4));

	GetSprite()->SetCastShadow(true);

}

// Moves the player given some vector delta
// Left/Right : -Y/+Y
// Up/Down : +X/-X
void ACharacterBase::Move(FVector2D delta)
{
	FVector newLocation = GetActorLocation();

	delta.Normalize();

	Velocity.X = delta.X * MovementSpeed * DeltaTime * 1000.f;
	Velocity.Y = delta.Y * MovementSpeed * DeltaTime * 1000.f;

	newLocation.X += Velocity.X;
	newLocation.Y += Velocity.Y;

	SetActorLocation(newLocation);
}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* playerInputComponent)
{
	Super::SetupPlayerInputComponent(playerInputComponent);
}

// Called every frame
void ACharacterBase::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	DeltaTime = deltaTime;

	Running = Velocity != FVector(0, 0, 0);

	// Flip the sprite based on the direction we are moving
	// Left/Right : -Y/+Y
	// Up/Down : +X/-X
	if (Velocity.Y > 0 && Velocity.X == 0)
	{
		Direction = Direction::Right;
	}
	else if (Velocity.Y > 0 && Velocity.X < 0)
	{
		Direction = Direction::BottomRight;
	}
	else if (Velocity.Y == 0 && Velocity.X < 0)
	{
		Direction = Direction::Bottom;
	}
	else if (Velocity.Y < 0 && Velocity.X < 0)
	{
		Direction = Direction::BottomLeft;
	}
	else if (Velocity.Y < 0 && Velocity.X == 0)
	{
		Direction = Direction::Left;
	}
	else if (Velocity.Y < 0 && Velocity.X > 0)
	{
		Direction = Direction::TopLeft;
	}
	else if (Velocity.Y == 0 && Velocity.X > 0)
	{
		Direction = Direction::Top;
	}
	else if (Velocity.Y > 0 && Velocity.X > 0)
	{
		Direction = Direction::TopRight;
	}

	//UE_LOG(LogTemp, Display, TEXT("(%f, %f)"), Velocity.X, Velocity.Y);
	//if (Velocity.X < 0)
	//{
	//	GetSprite()->SetRelativeRotation(FRotator(0, -270.f, CameraAngle));
	//}

	//if (Velocity.X > 0)
	//{
	//	GetSprite()->SetRelativeRotation(FRotator(0, -90.f, -CameraAngle));
	//}

	//Set the correct sprite based on our state
	//if (Running)
	//{
	//	//GetSprite()->SetFlipbook(RunningFlipbook);
	//	//UE_LOG(LogTemp, Display, TEXT("Pos: %f, %f"), GetActorLocation().X, GetActorLocation().Y);
	//}
	//else
	//{
	//	GetSprite()->SetFlipbook(IdleFlipbook);
	//}
	UpdateSprite();

	Velocity = FVector(0, 0, 0);

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Update sprite based on state
void ACharacterBase::UpdateSprite()
{
	if (Running)
	{
		switch (Direction)
		{
		case Direction::Right:
			GetSprite()->SetFlipbook(RunningFlipbook_Right);
			break;
		case Direction::BottomRight:
			GetSprite()->SetFlipbook(RunningFlipbook_BottomRight);
			break;
		case Direction::Bottom:
			GetSprite()->SetFlipbook(RunningFlipbook_Bottom);
			break;
		case Direction::BottomLeft:
			GetSprite()->SetFlipbook(RunningFlipbook_BottomLeft);
			break;
		case Direction::Left:
			GetSprite()->SetFlipbook(RunningFlipbook_Left);
			break;
		case Direction::TopLeft:
			GetSprite()->SetFlipbook(RunningFlipbook_TopLeft);
			break;
		case Direction::Top:
			GetSprite()->SetFlipbook(RunningFlipbook_Top);
			break;
		case Direction::TopRight:
			GetSprite()->SetFlipbook(RunningFlipbook_TopRight);
			break;
		}
	}
	else
	{
		switch (Direction)
		{
		case Direction::Right:
			break;
		case Direction::BottomRight:
			break;
		case Direction::Bottom:
			break;
		case Direction::BottomLeft:
			break;
		case Direction::Left:
			break;
		case Direction::TopLeft:
			break;
		case Direction::Top:
			break;
		case Direction::TopRight:
			break;
		}
	
	}
}
