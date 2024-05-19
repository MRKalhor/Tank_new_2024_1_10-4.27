// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tank_TopDown_Die.generated.h"

UCLASS()
class TANK_NEW_2024_1_10_API ATank_TopDown_Die : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATank_TopDown_Die();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* enemybody;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* enemybarrel;

	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* scenecomponent;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* fire;

	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* firesound;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* smoke;
};
