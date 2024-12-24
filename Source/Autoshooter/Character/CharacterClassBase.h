// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "WeaponBase.h"
#include "UObject/UObjectGlobals.h"
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

	void Tick(float deltaTime) override;

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
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UWeaponBase> WeaponClass;

	TObjectPtr<UWeaponBase> Weapon;

private:
	GENERATED_BODY()
	
};
