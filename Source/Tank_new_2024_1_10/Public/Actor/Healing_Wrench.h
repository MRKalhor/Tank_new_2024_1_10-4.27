// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Healing_Wrench.generated.h"

UCLASS()
class TANK_NEW_2024_1_10_API AHealing_Wrench : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealing_Wrench();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* meshactor;
	UPROPERTY(EditAnywhere, Category = "Components")
	class UBoxComponent* boxcomponents;

	/*UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class APawn_Tank>player;*/

	UPROPERTY(EditAnywhere, Category = "Advance")
	FDamageEvent DamageEvent;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* HealingParticle = nullptr;

	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* soundbase;

	virtual void NotifyActorBeginOverlap(AActor* otherActor)override;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float HealingAmountMax = 20;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class UDamageType> DamageTypeClass;

	APawn* player;
	
};
