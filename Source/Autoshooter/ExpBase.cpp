// Fill out your copyright notice in the Description page of Project Settings.


#include "ExpBase.h"

// Sets default values
AExpBase::AExpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	checkf(CollisionSphere, TEXT("Failed to create CollisionSphere"));

	RootComponent = CollisionSphere;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	checkf(Sprite, TEXT("Failed to create Sprite"));
	Sprite->SetupAttachment(CollisionSphere);
	Sprite->SetRelativeLocationAndRotation(FVector(0, 0, -32), FRotator(0, 90, -45));
	Sprite->SetRelativeScale3D(FVector(0.75, 0.75, 0.75));
}

// Called when the game starts or when spawned
void AExpBase::BeginPlay()
{
	Super::BeginPlay();

	StartingPos = GetActorLocation();
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AExpBase::OnComponentBeginOverlap);
}

// Called every frame
void AExpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Triggered)
	{
		TimeElapsed = FMath::Clamp((FDateTime::Now().ToUnixTimestampDecimal() - StartingDeltaTime) / MaxTime, 0, 1);

		FVector targetLocation = CharacterBase->GetActorLocation();
		targetLocation.Z = StartingPos.Z;

		float time = AnimationCurve->GetFloatValue(TimeElapsed);
		FVector newLocation = FMath::Lerp(StartingPos, targetLocation, time);

		SetActorLocation(newLocation);
	}
}

void AExpBase::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto* actor = Cast<ACharacterBase>(OtherActor);
	if (actor)
	{
		CharacterBase = actor;
		if (!Triggered)
		{
			Triggered = true;
			StartingDeltaTime = FDateTime::Now().ToUnixTimestampDecimal();
		}

		if (OtherComp->GetName() == "CollisionCylinder")
		{
			ACharacterClassBase* CharacterClassBase = Cast<ACharacterClassBase>(OtherActor);
			if (CharacterClassBase)
			{
				CharacterClassBase->AddExp(ExpValue);
				Destroy();
			}

		}
	}
}

