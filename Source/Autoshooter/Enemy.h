// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class AUTOSHOOTER_API AEnemy : public AActor
{
public:
	AEnemy();

protected:
	//UPROPERTY(EditAnywhere, Category="Components")
	//TObjectPtr<class USceneComponent> Root = nullptr;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<class UCapsuleComponent> CapsuleComponent = nullptr;

	UPROPERTY(EditAnywhere, Category="Components")
	TObjectPtr<class UPaperFlipbookComponent> FlipbookComponent = nullptr;


private:

	GENERATED_BODY()
	
};
