// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperFlipbookComponent.h"
#include "Components/SphereComponent.h"
#include "Autoshooter/Enemy.h"
#include "ProjectileBase.generated.h"

UCLASS(Abstract, Blueprintable)
class AUTOSHOOTER_API AProjectileBase : public AActor
{
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PlayAnimation();

	UFUNCTION()
	void Show();

	UFUNCTION()
	virtual void ShowAnimation();

	UFUNCTION()
	virtual void HideAnimation();

	UFUNCTION()
	virtual void ActivateCollision();

	UFUNCTION()
	virtual void DisableCollision();

	UFUNCTION()
	virtual void Hide();

	virtual void UpdatePosition(FVector newPos);
	virtual void UpdateRotation(FRotator newRotation);

	bool GetIsActive();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbook> Sprite = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UPaperFlipbookComponent> FlipbookComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AEnemy> EnemyClassType;


	bool IsActive = false;
private:
	GENERATED_BODY()

};
