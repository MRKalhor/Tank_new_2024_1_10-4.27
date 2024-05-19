// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Min.generated.h"

UCLASS()
class TANK_NEW_2024_1_10_API AMin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* otherActor)override;

private:

	UPROPERTY(Editanywhere, Category = "Component")
	UStaticMeshComponent* meshcomponent;

	UPROPERTY(Editanywhere, Category = "Component")
	UStaticMeshComponent* meshcomponent2;

	UPROPERTY(Editanywhere, Category = "Component")
	class UBoxComponent* boxcomponent;


	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<  UDamageType > DamageTypeClass;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float BaseDamage = 35;

	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* SoundFire;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* partialsystem;

	UPROPERTY(Editanywhere, Category = "Advance")
	float LockAtTargets = 1200;

	UPROPERTY(Editanywhere, Category = "Advance")
	float Firerate = 1;

	UPROPERTY(Editanywhere, Category = "Advance")
	float Firetimer = 0;

	UPROPERTY(Editanywhere, Category = "Advance")
	AActor* playerpawn = nullptr;

};
