// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ammo_Box.generated.h"

UCLASS()
class TANK_NEW_2024_1_10_API AAmmo_Box : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmo_Box();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Boxmesh;

	UPROPERTY(Editanywhere, Category = "Components")
	class UHealthComponent* healthcomponents;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class AHealing_Wrench>Healing_wrench;
};
