// Fill out your copyright notice in the Description page of Project Settings.

#include "Actor/LCVP.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ALCVP::ALCVP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LCVP = CreateDefaultSubobject<UStaticMeshComponent>("LCVP");
	RootComponent = LCVP;
	door = CreateDefaultSubobject<UStaticMeshComponent>("door");
	door->SetupAttachment(LCVP);
	trigger = CreateDefaultSubobject<UBoxComponent>("Trigger");
	trigger->SetupAttachment(LCVP);
}

// Called when the game starts or when spawneda
void ALCVP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALCVP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALCVP::NotifyActorBeginOverlap(AActor* otherActor)
{
	Super;
	Ereturn = true;
	UE_LOG(LogTemp,Warning,TEXT("LCVP : begin overlab"))
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Black, FString::Printf(TEXT("Bool: %s"), Ereturn ? TEXT("true") : TEXT("false")));
		}
}

void ALCVP::NotifyActorEndOverlap(AActor* otherActor)
{
	Ereturn = false;
	UE_LOG(LogTemp, Warning, TEXT("LCVP : end overlab"))
}

