// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Autoshooter/Character/WeaponBase.h"
#include "GreatswordWeapon.generated.h"

/**
 * 
 */
UCLASS()
class AUTOSHOOTER_API UGreatswordWeapon : public UWeaponBase
{
public:
	UGreatswordWeapon();

	void BeginPlay() override;
	void Initialize(UWorld* world, FVector position) override;
	void WeaponTimer() override;

protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	GENERATED_BODY()
	
};
