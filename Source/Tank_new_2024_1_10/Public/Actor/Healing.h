// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/HealthComponent.h"
#include "Healing.generated.h"


UCLASS()
class TANK_NEW_2024_1_10_API AHealing : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealing();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* meshactor;
	UPROPERTY(EditAnywhere, Category = "Components")
	class UBoxComponent* boxcomponents;

	UPROPERTY(EditAnywhere, Category = "Advance")
	APawn* playerpawn = nullptr;

	UPROPERTY(EditAnywhere, Category = "Advance")
	FDamageEvent DamageEvent;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* HealingParticle = nullptr;

	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* soundbase;

private:

	virtual void NotifyActorBeginOverlap(AActor* otherActor)override;
	virtual void NotifyActorEndOverlap(AActor* otherActor)override;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float HealingAmountMax = 1;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class UDamageType> DamageTypeClass;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float healingtime = 2;

	UPROPERTY(EditAnywhere, Category = "Advance")
	bool overlab = false;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UHealthComponent* CHealthComponents;

	int CurrentHealth;
	

};
