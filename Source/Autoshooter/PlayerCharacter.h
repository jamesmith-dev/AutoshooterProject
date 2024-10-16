// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class AUTOSHOOTER_API APlayerCharacter : public APaperCharacter
{
public:
	APlayerCharacter();

	void Move(FVector2D Delta);

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* playerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<class UCameraComponent> CameraComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks")
	TObjectPtr<UPaperFlipbook> IdleFlipbook = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks")
	TObjectPtr<UPaperFlipbook> RunningFlipbook = nullptr;

	UPROPERTY(EditAnywhere, Category="Character Stats")
	float MovementSpeed = 1.0f;

private:
	float DeltaTime = 0.f;
	FVector Velocity = { 0, 0, 0 };
	float CameraAngle = 45.f;
	bool Running = false;

private:
	GENERATED_BODY()
	
};
