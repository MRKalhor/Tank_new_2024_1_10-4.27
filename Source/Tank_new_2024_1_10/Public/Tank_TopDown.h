// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank_TopDown.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(Fconnectenemyhealth,float,health);

UCLASS()
class TANK_NEW_2024_1_10_API ATank_TopDown : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank_TopDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	Fconnectenemyhealth connectenemyhealth;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(Editanywhere, Category = "Components")
	UStaticMeshComponent* tankbody;

	UPROPERTY(Editanywhere, Category = "Components")
	UStaticMeshComponent* tankturet;

	UPROPERTY(Editanywhere, Category = "Components")
	UStaticMeshComponent* tankbarrel;

	UPROPERTY(Editanywhere, Category = "Components")
	USceneComponent* scenecomponent;

	UPROPERTY(Editanywhere, Category = "Components")
	class UHealthComponent* healthcomponents;

	/*UPROPERTY(Editanywhere, Category = "Components")
	class UBoxComponent* boxcomponent;*/

	UPROPERTY(Editanywhere, Category = "Advance")
	float LockAtTargets = 1200;

	void LockAtTarget(FVector target);


	UPROPERTY(Editanywhere, Category = "Advance")
	float Turretspeed_Rotation = 3;

	UPROPERTY(Editanywhere, Category = "Advance")
	float Firerate = 2;

	UPROPERTY(Editanywhere, Category = "Advance")
	float Firetimer = 0;

	UPROPERTY(Editanywhere, Category = "Advance")
	USoundBase* SoundFire;

	AActor* playerpawn;

	void fire();

	UPROPERTY(Editanywhere, Category = "Advance")
	TSubclassOf<class ABullet>Projectileclass;


};
