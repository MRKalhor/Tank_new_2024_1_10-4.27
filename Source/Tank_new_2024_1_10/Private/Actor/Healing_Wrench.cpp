// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Healing_Wrench.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Pawn_Tank.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHealing_Wrench::AHealing_Wrench()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshactor = CreateDefaultSubobject <UStaticMeshComponent>("ObjectActor");
	RootComponent = meshactor;
	boxcomponents = CreateDefaultSubobject<UBoxComponent>("BoxTrigger");
	boxcomponents->SetupAttachment(meshactor);
}

// Called when the game starts or when spawned
void AHealing_Wrench::BeginPlay()
{
	Super::BeginPlay();
	player = UGameplayStatics::GetPlayerPawn(this, 0);
	FVector location = GetActorLocation();
	FVector Flocation = FVector(location.X, location.Y, location.Z + 50);
	SetActorLocation(Flocation);
	SetActorRotation(FRotator(0, -70, 0));
}

// Called every frame
void AHealing_Wrench::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHealing_Wrench::NotifyActorBeginOverlap(AActor* otherActor)
{
	if (otherActor == player)
	{
		if (HealingParticle != NULL)
		{
			player->TakeDamage(-HealingAmountMax, DamageEvent, nullptr, this);
				
			UGameplayStatics::SpawnEmitterAtLocation(this, HealingParticle, boxcomponents->GetComponentLocation());
			UGameplayStatics::PlaySoundAtLocation(this, soundbase, boxcomponents->GetComponentLocation());
			Destroy();
		}
	}
}

