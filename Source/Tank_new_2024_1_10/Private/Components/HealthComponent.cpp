// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "Tank_TopDown.h"
#include "Pawn_Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Tank_TopDown.h"
#include "Components/SceneComponent.h"
#include "Enemy/Tank_TopDown_Die.h"
#include "Actor/Ammo_Box.h"
#include "Actor/Healing_Wrench.h"
#include "TankGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Widget/Enemy_Health_Bar.h"



// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	CurrentHealth = DeafualtHealth;
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = DeafualtHealth;
	 healthbar=Cast<UEnemy_Health_Bar>(EnemyHealthBar);

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	 players = UGameplayStatics::GetPlayerPawn(this,0);
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	timee = GetWorld()->GetDeltaSeconds();
}

void UHealthComponent::EventUpdateEnemyHealth()
{
	ATank_TopDown* player = Cast<ATank_TopDown>(GetOwner());
	player->connectenemyhealth.Broadcast(CurrentHealth);
	
	

}


void UHealthComponent::TakeDamage(AActor* DanageActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	if (Damage == 0) return;
	if (0 <= CurrentHealth && CurrentHealth <= 100)
	{
		CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, DeafualtHealth);
	}
	if (APawn_Tank* player = Cast<APawn_Tank>(GetOwner()))
	{
		player->OnHealthChange.Broadcast(CurrentHealth);
		if (CurrentHealth <= 0)
		{
			if (player_die_WIdget)
			{
				UUserWidget* createwin = CreateWidget<UUserWidget>(GetWorld(), player_die_WIdget, FName("Win widget"));
				createwin->AddToViewport();
			}
			else { UE_LOG(LogTemp, Warning, TEXT("Tnakgamemodebase : Win empity")) }

			UGameplayStatics::SetGlobalTimeDilation(this, 0);
			GetWorld()->GetFirstPlayerController()->DisableInput(GetWorld()->GetFirstPlayerController());
		}
	}
	if (ATank_TopDown* Enemy = Cast<ATank_TopDown>(GetOwner()))
	{
		Enemy->connectenemyhealth.Broadcast(CurrentHealth);
		EventUpdateEnemyHealth();
		UE_LOG(LogTemp, Warning, TEXT("Health components  : EVENT EventUpdateEnemyHealth Broadcast"))
		//Enemy_Health_Bar->SetVisibility(ESlateVisibility::Visible);

			if (healthbar)
			{
				healthbar->ONEnemyHealthBar.Broadcast();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("healthcomponents : healthbar faild"));
			}
		
	}
	if (CurrentHealth > 0) {
		UE_LOG(LogTemp, Warning, TEXT("Damage -20"));
		UE_LOG(LogTemp, Warning, TEXT("your health %f"), CurrentHealth);
	}

	if (CurrentHealth <= 0)
	{
		if (GetOwner() != nullptr)
		{
			FTransform enemylocation = GetOwner()->GetActorTransform();

			GetOwner()->Destroy();

			if (GetWorld()->SpawnActor<ATank_TopDown_Die>(Enemy_Die, enemylocation)) {
				GetWorld()->SpawnActor<ATank_TopDown_Die>(Enemy_Die, enemylocation);
				auto gamemode = UGameplayStatics::GetGameMode(this);
				ATankGameModeBase* ATankGameMode = Cast<ATankGameModeBase>(gamemode);

				ATankGameMode->EnemyDie();
			}
			if (!players || !players->IsPendingKill()) {
				UGameplayStatics::PlaySoundAtLocation(this, SoundDestroy, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
				UGameplayStatics::SpawnEmitterAtLocation(this, ParticleSystemDestroy, GetOwner()->GetActorLocation());

				UGameplayStatics::SpawnEmitterAtLocation(this, ParticleSystemDestroy2, GetOwner()->GetActorLocation());
				
			}
			if (!Box_Die || !Box_Die->IsPendingKill())
			{
				UE_LOG(LogTemp, Warning, TEXT("HealthComponet = box timer 2 faild time = %f _timer = %f"), timee, timer);
				GetWorld()->SpawnActor<AHealing_Wrench>(Wrench, enemylocation);
				//GetWorld()->SpawnActor<AActor>(Wrenchs, enemylocation);
			}


			UGameplayStatics::PlaySoundAtLocation(this, SoundDestroy, GetOwner()->GetActorLocation(), GetOwner()->GetActorRotation());
			UGameplayStatics::SpawnEmitterAtLocation(this, ParticleSystemDestroy, GetOwner()->GetActorLocation());
			UGameplayStatics::SpawnEmitterAtLocation(this, ParticleSystemDestroy2, GetOwner()->GetActorLocation());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawn enemy die"));
			return;
		}
	}
}