// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProjectileBase.h"
#include "UObject/UObjectGlobals.h"
#include "WeaponBase.generated.h"


UCLASS(Abstract, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AUTOSHOOTER_API UWeaponBase : public UActorComponent
{
public:	
	// Sets default values for this component's properties
	UWeaponBase();

	virtual void Initialize(UWorld* world, FVector position);
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual AProjectileBase* Fire();

	void SetWorld(UWorld* world);
	void SetPosition(FVector position);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

	virtual void WeaponTimer();
protected:
	UPROPERTY(EditDefaultsOnly);
	TSubclassOf<AProjectileBase> ProjectileToSpawn;
	TObjectPtr<AProjectileBase> Projectile;

	UWorld* World = nullptr;
	FVector Position;
	FTimerHandle WeaponTimerHandle;

private:		
	GENERATED_BODY()
};
