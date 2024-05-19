// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Ammo_Box.h"
#include "Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Actor/Healing_Wrench.h"



// Sets default values
AAmmo_Box::AAmmo_Box()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Boxmesh = CreateDefaultSubobject<UStaticMeshComponent>("Boxmesh");
	RootComponent = Boxmesh;
	healthcomponents = CreateDefaultSubobject<UHealthComponent>("healthcomponents");
}

// Called when the game starts or when spawned
void AAmmo_Box::BeginPlay()
{
	Super::BeginPlay();
	FTransform location = GetActorTransform();

	
}

// Called every frame
void AAmmo_Box::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

