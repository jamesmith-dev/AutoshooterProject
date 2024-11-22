// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterClassBase.h"

ACharacterClassBase::ACharacterClassBase()
	: ACharacterBase()
{

}

void ACharacterClassBase::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	Weapon->SetPosition(GetActorLocation());
}
