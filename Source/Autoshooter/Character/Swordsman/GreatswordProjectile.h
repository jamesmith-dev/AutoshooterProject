// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"

#include "Autoshooter/Character/ProjectileBase.h"
#include "GreatswordProjectile.generated.h"

/**
 * 
 */
UCLASS()
class AUTOSHOOTER_API AGreatswordProjectile : public AProjectileBase
{
public:
	AGreatswordProjectile();

	void Tick(float DeltaTime) override;

	void ShowAnimation() override;
	void HideAnimation() override;

	void ActivateCollision() override;
	void DisableCollision() override;

	void Hide() override;

	void UpdatePosition(FVector newPos) override;
	void UpdateRotation(FRotator newRotation) override;

protected:
	void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	//UPROPERTY(EditAnywhere)
	//TObjectPtr<USphereComponent> SphereCollisionComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> BoxCollisionComponent = nullptr;

private:

	GENERATED_BODY()
	
};
