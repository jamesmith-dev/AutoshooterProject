// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"

#include "Autoshooter/AbilityBase.h"
#include "CharacterBase.generated.h"

UENUM(BlueprintType)
enum class Direction : uint8
{
	Right,
	BottomRight,
	Bottom,
	BottomLeft,
	Left,
	TopLeft,
	Top,
	TopRight
};

UCLASS()
class AUTOSHOOTER_API ACharacterBase : public APaperCharacter
{
public:
	ACharacterBase();

	void Move(FVector2D delta);

	virtual void Tick(float deltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* playerInputComponent) override;

	void AddAbility(UAbilityBase ability);
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<class UCameraComponent> CameraComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks")
	TObjectPtr<UPaperFlipbook> IdleFlipbook = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Right"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_Right = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Bottom Right"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_BottomRight = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Bottom"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_Bottom = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Bottom Left"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_BottomLeft = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Left"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_Left = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Top Left"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_TopLeft = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Top"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_Top = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Flipbooks|Running", meta=(DisplayName="Top Right"))
	TObjectPtr<UPaperFlipbook> RunningFlipbook_TopRight = nullptr;


	TArray<UAbilityBase> AbilityList;

protected:
	UPROPERTY(EditAnywhere, Category="Stats|Miscellaneous")
	float MovementSpeed = 1.0f;
	Direction Direction = Direction::Right;

private:
	float DeltaTime = 0.f;
	FVector Velocity = { 0, 0, 0 };
	float CameraAngle = 45.f;
	bool Running = false;
	const int MAX_ITEM_SLOTS = 6; // Subject to change

private:
	void UpdateSprite();
private:
	GENERATED_BODY()
	
};
