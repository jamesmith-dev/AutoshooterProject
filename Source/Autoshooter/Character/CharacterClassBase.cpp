// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterClassBase.h"
#include "Blueprint/UserWidget.h"

ACharacterClassBase::ACharacterClassBase()
	: ACharacterBase()
{
	PickupSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphere"));
	checkf(PickupSphere, TEXT("Failed to create PickupSphere"));
	PickupSphere->SetupAttachment(RootComponent);
	PickupSphere->SetSphereRadius(300); // TODO: Add PickupRange to this calculation

}

void ACharacterClassBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(ExpBarClass))
	{
		ExpBar = CreateWidget<UUserWidget>(GetWorld(), ExpBarClass);

		if (ExpBar)
		{
			ExpBar->AddToViewport();
		}
	}
}

void ACharacterClassBase::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	Weapon->SetPosition(GetActorLocation());
}

void ACharacterClassBase::AddExp(int exp)
{
	CurrentExp += exp * ExpGain;
	UE_LOG(LogTemp, Warning, TEXT("Current Exp: %d"), CurrentExp); 	

	if (CurrentExp >= TotalExpForLevelUp)
	{
		int remainder = CurrentExp - TotalExpForLevelUp;
		LevelUp();
		CurrentExp = remainder;
	}
}

void ACharacterClassBase::LevelUp()
{
	ExpLevel++;

	// Calculate total exp needed for the next level up
	TotalExpForLevelUp = floor( (25 * pow(0.95, ExpLevel) + 10 * pow(1.04, ExpLevel) + 6) * ExpLevel);

	UE_LOG(LogTemp, Warning, TEXT("Current Level: %d"), ExpLevel); 	
	UE_LOG(LogTemp, Warning, TEXT("TotalExpForLevelUp: %d"), TotalExpForLevelUp); 	
}

int ACharacterClassBase::GetCurrentExp()
{
	return CurrentExp;
}

int ACharacterClassBase::GetExpLevel()
{
	return ExpLevel;
}

int ACharacterClassBase::GetTotalExpForLevelUp()
{
	return TotalExpForLevelUp;
}
