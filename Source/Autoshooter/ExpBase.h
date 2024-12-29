// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperFlipbookComponent.h"
#include "Components/SphereComponent.h"
#include "Character/CharacterBase.h"
#include "Character/CharacterClassBase.h"
#include "ExpBase.generated.h"

UCLASS()
class AUTOSHOOTER_API AExpBase : public AActor
{
	
public:	
	// Sets default values for this actor's properties
	AExpBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UPaperFlipbookComponent> Sprite = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> CollisionSphere = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UCurveFloat> AnimationCurve = nullptr;

	UPROPERTY(EditAnywhere)
	float MaxTime = 0.8f;

	UPROPERTY(EditAnywhere)
	int ExpValue;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);

private:
	bool Triggered = false;
	double StartingDeltaTime = 0.0;
	double TimeElapsed = 0.0;
	FVector StartingPos;
	ACharacterBase* CharacterBase;

private:
	GENERATED_BODY()
};
