// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityBase.generated.h"

UENUM()
enum class UpgradeLevel : uint8
{
	None = 0,
	One,
	Two,
	Max
};

//UCLASS( Abstract, Blueprintable, ClassGroup=(Ability), meta=(BlueprintSpawnableComponent) )
UCLASS()
class AUTOSHOOTER_API UAbilityBase : public UActorComponent
{

public:	
	// Sets default values for this component's properties
	UAbilityBase();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void Activate();

protected:

	// Stats
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditInstanceOnly)
	float Duration;

	UPROPERTY(EditInstanceOnly)
	float Cooldown;

	UPROPERTY(EditInstanceOnly)
	float AttackSpeed;

	UPROPERTY(EditInstanceOnly)
	float Range;

	UPROPERTY(EditInstanceOnly)
	float ProjectileSize;

	// TODO: Come back to this later
	//UPROPERTY(EditInstanceOnly)
	//float Arc;

	UPROPERTY(EditInstanceOnly)
	UpgradeLevel UpgradeLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UPaperFlipbook> Animation;

	UPROPERTY(EditInstanceOnly)
	TObjectPtr<UStaticMesh> CollisionMesh;

private:
	GENERATED_BODY()
};
