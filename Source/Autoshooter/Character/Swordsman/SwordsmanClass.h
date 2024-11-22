// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Autoshooter/Character/CharacterClassBase.h"
#include "SwordsmanClass.generated.h"

/**
 * 
 */
UCLASS()
class AUTOSHOOTER_API ASwordsmanClass : public ACharacterClassBase
{
public:
	ASwordsmanClass();

	void BeginPlay() override;

private:
	GENERATED_BODY()
	
};
