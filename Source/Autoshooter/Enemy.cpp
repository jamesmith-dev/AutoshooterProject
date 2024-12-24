// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Components/CapsuleComponent.h"
#include "PaperFlipbookComponent.h"

AEnemy::AEnemy()
{
	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//RootComponent = Root;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCapsule"));
	checkf(CapsuleComponent, TEXT("Failed to create Capsule"));
	CapsuleComponent->SetupAttachment(RootComponent);
	//CapsuleComponent->SetupAttachment(RootComponent);

	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	checkf(FlipbookComponent, TEXT("Failed to create Flipbook"));
	FlipbookComponent->SetupAttachment(CapsuleComponent);

}
