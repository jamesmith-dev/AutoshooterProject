// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "WeaponBase.h"
#include "UObject/UObjectGlobals.h"
#include "Components/SphereComponent.h"
#include "CharacterClassBase.generated.h"

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class AbilityTypes : uint8
{
	None		= 0 UMETA(Hidden),
	Melee		= 1 << 0,
	Ranged		= 1 << 1,
	Physical	= 1 << 2,
	Magic		= 1 << 3,
};
ENUM_CLASS_FLAGS(AbilityTypes)
/**
 * 
 */
UCLASS()
class AUTOSHOOTER_API ACharacterClassBase : public ACharacterBase
{
public:
	ACharacterClassBase();

	virtual void BeginPlay() override;

	void Tick(float deltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AddExp(int exp);

	UFUNCTION(BlueprintCallable)
	int GetCurrentExp();

	UFUNCTION(BlueprintCallable)
	int GetExpLevel();

	UFUNCTION(BlueprintCallable)
	int GetTotalExpForLevelUp();

protected:

	// Offensive Stats
	UPROPERTY(EditAnywhere, Category="Stats|Offensive")
	float AttackDamage;
	UPROPERTY(EditAnywhere, Category="Stats|Offensive")
	float AbilityDamage;
	UPROPERTY(EditAnywhere, Category="Stats|Offensive", meta=(Bitmask, BitmaskEnum=AbilityTypes))
	uint8 AbilityAttunement;
	UPROPERTY(EditAnywhere, Category="Stats|Offensive", meta=(Bitmask, BitmaskEnum=AbilityTypes))
	uint8 AbilityWeakness;

	// Defensive Stats
	UPROPERTY(EditAnywhere, Category="Stats|Defensive")
	float Health;
	UPROPERTY(EditAnywhere, Category="Stats|Defensive")
	float Defense;
	UPROPERTY(EditAnywhere, Category="Stats|Defensive")
	float Regeneration;
	UPROPERTY(EditAnywhere, Category="Stats|Defensive")
	float BlockChance;

	// Critical Stats
	UPROPERTY(EditAnywhere, Category="Stats|Critical")
	float CritChance;
	UPROPERTY(EditAnywhere, Category="Stats|Critical")
	float CritDamage;

	// Miscellaneous
	// Movement Speed is in ACharacterBase
	UPROPERTY(EditAnywhere, Category="Stats|Miscellaneous")
	float ExpGain;
	UPROPERTY(EditAnywhere, Category="Stats|Miscellaneous")
	float PickupRange;	

	// Experience and Level
	int ExpLevel = 1;
	int CurrentExp = 0;
	int TotalExpForLevelUp = 40;
	
	UPROPERTY(EditDefaultsOnly, Category="Class Types")
	TSubclassOf<UWeaponBase> WeaponClass;

	TObjectPtr<UWeaponBase> Weapon;

	TObjectPtr<USphereComponent> PickupSphere;

	UPROPERTY(EditAnywhere, Category="Class Types")
	TSubclassOf<UUserWidget> ExpBarClass;

	TObjectPtr<UUserWidget> ExpBar;

protected:
	void LevelUp();

private:
	GENERATED_BODY()
	
};
