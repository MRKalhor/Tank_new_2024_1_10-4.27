// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawn_Tank.h"
#include "Components/HealthComponent.h"
#include "Actor/Bullet.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/GameplayStatics.h"
#include "Widget/MyUserWidget.h"

// Sets default values
APawn_Tank::APawn_Tank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshcomponent = CreateDefaultSubobject<UStaticMeshComponent>("Tank_Pawn");
	RootComponent = meshcomponent;


	Tankturret = CreateDefaultSubobject<UStaticMeshComponent>("Tank_turret");
	Tankturret->SetupAttachment(meshcomponent);

	tankbarrel = CreateDefaultSubobject<UStaticMeshComponent>("Tank_barrel");
	tankbarrel->SetupAttachment(Tankturret);

	armcomponent = CreateDefaultSubobject<USpringArmComponent>("Tank_Arm");
	armcomponent->SetupAttachment(Tankturret);

	camercompenet = CreateDefaultSubobject<UCameraComponent>("Tank_Camer");
	camercompenet->SetupAttachment(armcomponent);

	scenecomponent = CreateDefaultSubobject<USceneComponent>(TEXT("scenecomponent"));
	scenecomponent->SetupAttachment(tankbarrel);

	pawnmovment = CreateDefaultSubobject<UFloatingPawnMovement>("pawnmovment");
	healthcomponents = CreateDefaultSubobject<UHealthComponent>("HealthComponents");
}

// Called when the game starts or when spawned
void APawn_Tank::BeginPlay()
{
	Super::BeginPlay();

	if (GetOwner())
	{
		FVector ScLocation = scenecomponent->GetComponentLocation();
		ZCoordinate = ScLocation.Z;

		FVector ScLocation1 = GetOwner()->GetActorLocation();
		ZCoordinate1 = ScLocation.Z - 20;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn tank : Get Owner Empity(Owner not find) "))

	}

	UE_LOG(LogTemp, Warning, TEXT("Pawn tank : scenecomponent %f"), ZCoordinate)
		UE_LOG(LogTemp, Warning, TEXT("Pawn tank : meshcomponent %f"), ZCoordinate1)


}

// Called every frame
void APawn_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//event Ability
	Firetimer += GetWorld()->GetDeltaSeconds();

	////event Ability limit ablility timer
	FiretimerAB = FMath::Clamp(FiretimerAB, 0.0f, FirerateAB);
	FiretimerAB += GetWorld()->GetDeltaSeconds();


	eventOnAbilityTime.Broadcast(Firetimer);
	UpdateeventOnAbilityTime();

}

// Called to bind functionality to input
void APawn_Tank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APawn_Tank::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APawn_Tank::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight", this, &APawn_Tank::TurnRight);
	PlayerInputComponent->BindAxis("TurnUp", this, &APawn_Tank::TurnUp);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APawn_Tank::fire);
	PlayerInputComponent->BindAction("FireAB", IE_Pressed, this, &APawn_Tank::fireAB);
}

inline void APawn_Tank::MoveForward(float Fmove)
{
	if (ZCoordinate > ZCoordinate1)
	{
		AddMovementInput(GetActorForwardVector(), Fmove);
		if (Fmove != 0)
		{
			UGameplayStatics::PlaySoundAtLocation(this, movesound, meshcomponent->GetComponentLocation());
		}
		if (Fmove == 1 || Fmove == 0)
		{
			FFmove = false;
		}
		if (Fmove == -1)
		{
			FFmove = true;
		}
	}
}

void APawn_Tank::MoveRight(float move)
{
	//AddMovementInput(GetActorRightVector(), move);

	if (FFmove == true && (move == 1 || move == -1))
	{
		meshcomponent->AddRelativeRotation(FRotator(0, (move * -1) * Body_RotationSpeed * GetWorld()->GetDeltaSeconds(), 0));
		//UGameplayStatics::PlaySoundAtLocation(this, Sound, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
		UE_LOG(LogTemp, Warning, TEXT("Pawn tank : sound 1"));
	}
	if (FFmove == false)
	{
		meshcomponent->AddRelativeRotation(FRotator(0, move * Body_RotationSpeed * GetWorld()->GetDeltaSeconds(), 0));
		//UGameplayStatics::PlaySoundAtLocation(this, Sound, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
		/*UE_LOG(LogTemp, Warning, TEXT("sound 2"));*/
	}
}

void APawn_Tank::TurnRight(float move)
{
	this->AddControllerPitchInput(move);

	Tankturret->AddRelativeRotation(FRotator(0, move * Turret_RotationSpeed * GetWorld()->GetDeltaSeconds(), 0));
}

void APawn_Tank::TurnUp(float move)
{
	if (move > 0 && tankbarrel->GetRelativeRotation().Pitch >= 8)
		return;
	if (move < 0 && tankbarrel->GetRelativeRotation().Pitch <= -30)
		return;
	tankbarrel->AddRelativeRotation(FRotator(move * baral_RotationSpeed * GetWorld()->GetDeltaSeconds(), 0, 0));
}

void APawn_Tank::fire()
{
	if (Firetimer >= Firerate)
	{
		ABullet* bullet = GetWorld()->SpawnActor<ABullet>(Projectileclass, scenecomponent->GetComponentTransform());
		bullet->SetOwner(this);

		UGameplayStatics::PlaySoundAtLocation(bullet, SoundFire, tankbarrel->GetComponentLocation(), GetOwner()->GetActorRotation());
		UGameplayStatics::SpawnEmitterAtLocation(this, fireparticle, scenecomponent->GetComponentLocation());

		UE_LOG(LogTemp, Warning, TEXT("Pawn tank : Fire"));
		Firetimer = 0;
	}
}

void APawn_Tank::fireAB()
{
	/*float nowtimerAB=FMath::Clamp(Firetimer, Firetimer = 0, FirerateAB);
	UE_LOG(LogTemp,Warning,TEXT("Pawn tank : FirAb time = %d"),Firetimer- FirerateAB)*/
	UE_LOG(LogTemp, Warning, TEXT("Pawn tank : FiretimerAB = %f"), FiretimerAB)

		if (FiretimerAB >= FirerateAB)
		{
			ABullet* bulletAB = GetWorld()->SpawnActor<ABullet>(ProjectileclassAB, scenecomponent->GetComponentTransform());
			bulletAB->SetOwner(this);

			UGameplayStatics::PlaySoundAtLocation(bulletAB, SoundFire, tankbarrel->GetComponentLocation(), GetOwner()->GetActorRotation());
			UGameplayStatics::SpawnEmitterAtLocation(this, fireparticle, scenecomponent->GetComponentLocation());
			UE_LOG(LogTemp, Warning, TEXT("Pawn tank : FireAB"));
			FiretimerAB = 0;
		}
}

void APawn_Tank::UpdateeventOnAbilityTime()
{
	eventOnAbilityTime.Broadcast(FiretimerAB);
}

