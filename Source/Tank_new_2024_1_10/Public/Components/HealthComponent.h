// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANK_NEW_2024_1_10_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float DeafualtHealth = 100;

	UPROPERTY(EditAnywhere, Category = "Advance", BlueprintReadWrite)
	float CurrentHealth = DeafualtHealth;

	void EventUpdateEnemyHealth();

private:


	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* SoundDestroy;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* ParticleSystemDestroy;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* ParticleSystemDestroy2 = nullptr;

	/*UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<ATank_TopDown>enemy;*/

	UFUNCTION()
	void TakeDamage(AActor* DanageActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser);

	UPROPERTY(Editanywhere, Category = "Advance")
	TSubclassOf<class ATank_TopDown_Die> Enemy_Die;

	UPROPERTY(Editanywhere, Category = "Advance")
	TSubclassOf<class AAmmo_Box> Box_Die;

	UPROPERTY(Editanywhere, Category = "Advance")
	TSubclassOf<class AHealing_Wrench> Wrench;

	//UPROPERTY(Editanywhere, Category = "Advance")
	//TSubclassOf<class AActor> Wrenchs;

	UPROPERTY(Editanywhere, Category = "Advance")
	APawn* Enemy_Pawn;

	float timee = 0;

	UPROPERTY(Editanywhere, Category = "Advance")
	float timer = 2;

	APawn* players;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class UUserWidget>player_die_WIdget;

	TSubclassOf<class UEnemy_Health_Bar>EnemyHealthBar;

	UEnemy_Health_Bar* healthbar;
};