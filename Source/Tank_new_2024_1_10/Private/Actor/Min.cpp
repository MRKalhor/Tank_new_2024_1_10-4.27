// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Min.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
AMin::AMin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshcomponent = CreateDefaultSubobject<UStaticMeshComponent>("meshcomponent");
	RootComponent = meshcomponent;

	meshcomponent2 = CreateDefaultSubobject<UStaticMeshComponent>("meshcomponent2");
	meshcomponent2->SetupAttachment(meshcomponent);

	boxcomponent = CreateDefaultSubobject<UBoxComponent>("boxcomponent");
	boxcomponent->SetupAttachment(meshcomponent);
}

// Called when the game starts or when spawned
void AMin::BeginPlay()
{
	Super::BeginPlay();
    playerpawn = UGameplayStatics::GetPlayerPawn(this, 0);
}

// Called every frame
void AMin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
  /*  FVector playerlocation = playerpawn->GetActorLocation();
    if (FVector::Dist(this->GetActorLocation(), playerlocation) <= LockAtTargets)
    {
        if (Firetimer >= Firerate)
        {
            Firetimer = 0;
        }
        Firetimer += DeltaTime;
    }*/
}

void AMin::NotifyActorBeginOverlap(AActor* otherActor)
{
    if (UGameplayStatics::ApplyDamage(otherActor, BaseDamage, GetWorld()->GetFirstPlayerController(), this, DamageTypeClass))
    {
        UE_LOG(LogTemp, Warning, TEXT("Active now"));
        UGameplayStatics::ApplyDamage(otherActor, BaseDamage, GetWorld()->GetFirstPlayerController(), this, DamageTypeClass);
    
        /*if (SoundFire != nullptr)
        {
            UGameplayStatics::PlaySoundAtLocation(this, SoundFire, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
            UE_LOG(LogTemp, Warning, TEXT("Sound  found"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Sound not found"));
            return;
        }`
        if (partialsystem != nullptr)
        {
            UGameplayStatics::SpawnEmitterAtLocation(this, partialsystem, GetOwner()->GetActorLocation());
            UE_LOG(LogTemp, Warning, TEXT("Particle system  found"));
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Particle system not found"));
            return;
        }
        }
      else
     {
        UE_LOG(LogTemp, Warning, TEXT("Deactive Now"));
        return;*/
    }
}


