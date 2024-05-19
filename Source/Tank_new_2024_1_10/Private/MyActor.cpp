// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Pawn_Tank.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	meshcomponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent=meshcomponent;

	meshcomponent2 = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent2");
	meshcomponent2->SetupAttachment(meshcomponent);

	boxcomponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	boxcomponent->SetupAttachment(meshcomponent);

	
	
}

void AMyActor::NotifyActorBeginOverlap(AActor* otherActore)
{
	/*if (Door!=NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target Detected"));
		Door->SetActorLocation(FVector(0, 0, 300));
	}*/
	/*if (time>=timer)
	{
		GetWorld()->SpawnActor<APawn_Tank>(tankclass, meshcomponent->GetComponentTransform());
		time = 0;
	}
	time += GetWorld()->GetDeltaSeconds();*/
	UGameplayStatics::ApplyDamage(otherActore, BaseDamage, GetWorld()->GetFirstPlayerController(), this, DamageTypeClass);
	UGameplayStatics::PlaySoundAtLocation(this,SoundBase, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation() );
	//UGameplayStatics::SpawnEmitterAtLocation(this, partialsystem, GetOwner()->GetActorLocation());


}

void AMyActor::NotifyActorEndOverlap(AActor* otherActore)
{
	/*if (Door != NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("Target Out of the Rnage"));
		Door->SetActorLocation(FVector(0, 0, 110));
		
	}*/
	
	//Destroy();
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

