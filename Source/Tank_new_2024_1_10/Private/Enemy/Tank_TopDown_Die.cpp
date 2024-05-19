// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Tank_TopDown_Die.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATank_TopDown_Die::ATank_TopDown_Die()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	enemybody = CreateDefaultSubobject<UStaticMeshComponent>("enemybody");
	RootComponent	= enemybody;
	enemybarrel = CreateDefaultSubobject<UStaticMeshComponent>("enemybarrel");
	enemybarrel->SetupAttachment(enemybody);
	scenecomponent = CreateDefaultSubobject<USceneComponent>(TEXT("scenecomponent"));
	scenecomponent->SetupAttachment(enemybody);
}

// Called when the game starts or when spawned
void ATank_TopDown_Die::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::SpawnEmitterAtLocation(this, fire, scenecomponent->GetComponentLocation());
	UGameplayStatics::PlaySoundAtLocation(this, firesound, scenecomponent->GetComponentLocation());
	UGameplayStatics::SpawnEmitterAtLocation(this, smoke, enemybody->GetComponentLocation());

	
}

// Called every frame
void ATank_TopDown_Die::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

