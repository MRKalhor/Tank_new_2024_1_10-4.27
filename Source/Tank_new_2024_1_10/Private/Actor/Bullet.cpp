// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Bullet.h"
#include "Components/HealthComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBody"));
	RootComponent = mesh;
	mesh->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
	movmentcomponent = CreateDefaultSubobject<UProjectileMovementComponent>("PawnMovment");

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	 
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, GetWorld()->GetFirstPlayerController(), this, DamageTypeClass);
	UGameplayStatics::SpawnEmitterAtLocation(this,bulletparticle, mesh->GetComponentLocation());
	UGameplayStatics::PlaySoundAtLocation(this, HitSound, mesh->GetComponentLocation());
	Destroy();
}



