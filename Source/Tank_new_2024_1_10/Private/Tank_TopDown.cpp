// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_TopDown.h"

#include "Kismet/GameplayStatics.h"
#include "Actor/Bullet.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/BoxComponent.h"
#include "Components/HealthComponent.h"
#include "Components/ProgressBar.h"


// Sets default values
ATank_TopDown::ATank_TopDown()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	tankbody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("tankbody"));
	RootComponent = tankbody;

	tankturet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("tankturet"));
	tankturet->SetupAttachment(tankbody);

	tankbarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("tankbarrel"));
	tankbarrel->SetupAttachment(tankturet);

	scenecomponent = CreateDefaultSubobject<USceneComponent>(TEXT("scenecomponent"));
	scenecomponent->SetupAttachment(tankbarrel);

	healthcomponents = CreateDefaultSubobject<UHealthComponent>("HealthComponents");
	
	/*boxcomponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	boxcomponent->SetupAttachment(tankbody);*/

	this->SetActorScale3D(FVector(.7,.7,.7));

}

// Called when the game starts or when spawned
void ATank_TopDown::BeginPlay()
{
	Super::BeginPlay();
	


	//playerpawn = UGameplayStatics::GetPlayerPawn(this,0);
	TArray<AActor*> FoundPlayers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), FoundPlayers);

	for (AActor* Player : FoundPlayers)
	{
		APawn* PlayerPawnee = Cast<APawn>(Player);
		if (PlayerPawnee)
		{
			playerpawn = PlayerPawnee;
		}
	}
}

// Called every frame
void ATank_TopDown::Tick(float DeltaTime)
{
	FVector playerlocation = playerpawn->GetActorLocation();
	if (FVector::Dist(this->GetActorLocation(), playerlocation) <= LockAtTargets)
	{
		LockAtTarget(playerlocation);
		if (Firetimer >= Firerate)
		{
			fire();
			Firetimer = 0;
		}
		Firetimer += DeltaTime;
	}
}

void ATank_TopDown::LockAtTarget(FVector target)
{
	// Get the location of turret and barrel components
	FVector TurretLocation = tankturet->GetComponentLocation();
	FVector BarrelLocation = tankbarrel->GetComponentLocation();

	// Calculate the target location with the same Z-coordinate as turret
	FVector TargetFixLocation = FVector(target.X, target.Y, TurretLocation.Z);

	// Calculate rotation for turret
	FRotator NewTurretRotation = (TargetFixLocation - TurretLocation).Rotation();

	// Interpolate turret rotation
	FRotator NewRotation = FMath::Lerp(tankturet->GetComponentRotation(), NewTurretRotation, Turretspeed_Rotation * GetWorld()->GetDeltaSeconds());

	tankturet->SetWorldRotation(NewRotation);

	// Set the new rotation for turret
	FVector TargetFixLocation2 = FVector(target.X, target.Y, (target.Z-3));

	// Calculate rotation for barrel
	FRotator NewBarrelRotation = (TargetFixLocation2 - BarrelLocation).Rotation();

	// Interpolate barrel rotation
	FRotator NewRotationBarrel = FMath::Lerp(tankbarrel->GetComponentRotation(), NewBarrelRotation, Turretspeed_Rotation * GetWorld()->GetDeltaSeconds());

	// Set the new rotation for barrel
	tankbarrel->SetWorldRotation(NewRotationBarrel);
}


void ATank_TopDown::fire()
{
	ABullet* bullet=GetWorld()->SpawnActor<ABullet>(Projectileclass, scenecomponent->GetComponentTransform());
	UGameplayStatics::PlaySoundAtLocation(bullet, SoundFire, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());


	bullet->SetOwner(this);
	
	
}

// Called to bind functionality to input
void ATank_TopDown::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	PlayerInputComponent->BindAxis("MoveForward", this, &ATank_TopDown::MoveForward);
//	PlayerInputComponent->BindAxis("MoveRight", this, &ATank_TopDown::MoveRight);
//	//PlayerInputComponent->BindAxis("TurnRight", this, &ATank_TopDown::TurnRight);
//	//PlayerInputComponent->BindAxis("TurnUp", this, &ATank_TopDown::TurnUp);
//
}
//
//void ATank_TopDown::MoveForward(float move)
//{
//	AddMovementInput(GetActorForwardVector(), move);
//	if (move == 1)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("move forward"));
//
//	}if (move == -1)
//	{
//		UE_LOG(LogTemp, Warning, TEXT("move back"));
//
//	}
//}
//
//void ATank_TopDown::MoveRight(float move)
//{
//	AddMovementInput(GetActorRightVector(), move);
//}
//
//void ATank_TopDown::TurnUp(float move)
//{
//	
//	//this->AddControllerPitchInput(move);
//
//}
//
//void ATank_TopDown::TurnRight(float move)
//{
//	//this->AddControllerYawInput(move);
//}

