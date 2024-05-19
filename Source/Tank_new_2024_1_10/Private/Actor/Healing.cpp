// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Healing.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/HealthComponent.h"
#include "Components/AudioComponent.h"



// Sets default values
AHealing::AHealing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshactor=CreateDefaultSubobject <UStaticMeshComponent>("ObjectActor");
	RootComponent = meshactor;
	boxcomponents = CreateDefaultSubobject<UBoxComponent>("BoxTrigger");
	boxcomponents->SetupAttachment(meshactor);
	 
}

// Called when the game starts or when spawned
void AHealing::BeginPlay()
{
	Super::BeginPlay();
	playerpawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (CHealthComponents != nullptr)
	{
		CurrentHealth = CHealthComponents->CurrentHealth;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("CHealthComponents is nullptr!"));
	}
}

// Called every frame
void AHealing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AHealing::NotifyActorBeginOverlap(AActor* otherActor)
{
	if (otherActor != nullptr)
	{
		if (HealingParticle != NULL)
		{
			if (CurrentHealth <= 99) 
			{
				for (size_t i=CurrentHealth;i <= 98; i++)
				{
					playerpawn->TakeDamage(-HealingAmountMax, DamageEvent, nullptr, this);
				}
				UGameplayStatics::SpawnEmitterAtLocation(this, HealingParticle, boxcomponents->GetComponentLocation());
				UGameplayStatics::PlaySoundAtLocation(this, soundbase, boxcomponents->GetComponentLocation());
			}
		}
		
	}
	
}

void AHealing::NotifyActorEndOverlap(AActor* otherActor)
{
	
}

