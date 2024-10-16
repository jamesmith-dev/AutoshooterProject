// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoshooterPlayerController.h"

// Called when the controller possess our character
void AAutoshooterPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// Store the player reference
	GameCharacter = Cast<APlayerCharacter>(aPawn);
	checkf(GameCharacter, TEXT("AAutoshooterPlayerController can only possess APlayerCharacter pawns"));

	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	checkf(EnhancedInputComponent, TEXT("Unable to get reference to EnhancedInputComponent"));

	// Get local player subsystem
	UEnhancedInputLocalPlayerSubsystem* inputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	checkf(inputSubsystem, TEXT("Unable to get reference to the EnhancedInputLocalPlayerSubsystem"));

	// Wipe existing mappings and add our own mapping
	checkf(InputMappingContext, TEXT("InputMappingContext was not specified"));
	inputSubsystem->ClearAllMappings();
	inputSubsystem->AddMappingContext(InputMappingContext, 0);

	if (ActionMove)
	{
		EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, &AAutoshooterPlayerController::HandleMove);
	}

}

void AAutoshooterPlayerController::OnUnPossess()
{
	EnhancedInputComponent->ClearActionBindings();

	Super::OnUnPossess();
}

void AAutoshooterPlayerController::HandleMove(const FInputActionValue& InputActionValue)
{
	GameCharacter->Move(InputActionValue.Get<FVector2D>());
}
