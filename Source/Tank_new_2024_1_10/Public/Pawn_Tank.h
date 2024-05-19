// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Pawn_Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChange, float, health);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityTime, float, FirerateAB);

UCLASS()
class TANK_NEW_2024_1_10_API APawn_Tank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawn_Tank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnHealthChange OnHealthChange;

	UPROPERTY(BlueprintAssignable)
	FOnAbilityTime eventOnAbilityTime;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Fmove);
	void MoveRight(float move);
	void TurnRight(float move);
	void TurnUp(float move);


public:
	// event connctor(healthcomponent->healthWidget)
	UPROPERTY(EditAnywhere, Category = "Components", BlueprintReadWrite)
	UStaticMeshComponent* meshcomponent;

	UPROPERTY(EditAnywhere, Category = "Components", BlueprintReadWrite)
	UStaticMeshComponent* Tankturret;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* tankbarrel;

	UPROPERTY(EditAnywhere, Category = "Components")
	class USpringArmComponent* armcomponent;


	UPROPERTY(EditAnywhere, Category = "Components",BlueprintReadWrite)
	class UCameraComponent* camercompenet;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UFloatingPawnMovement* pawnmovment;

	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* scenecomponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	USceneComponent* scenecomponent1;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UHealthComponent* healthcomponents;

private:
	UPROPERTY(EditAnywhere, Category = "Advance")
	float Body_RotationSpeed =60;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float Turret_RotationSpeed = 60;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float baral_RotationSpeed = 150;
	
	UPROPERTY(EditAnywhere, Category = "Advance")
	float Firetimer = 0;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float Firerate = .75;


	UPROPERTY(EditAnywhere, Category = "Advance")
	float FiretimerAB=0;
	float FiretimerABCustom;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float FirerateAB = 20;


	UPROPERTY(EditAnywhere, Category = "Advance")
	bool BFire =false;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class ABullet>Projectileclass;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class ABullet>ProjectileclassAB;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class UMyUserWidget>UIWidget;

	UPROPERTY(Editanywhere, Category = "Advance")
	bool FFmove = false;

	UPROPERTY(EditAnywhere, Category = "Advance")
	 USoundBase* movesound;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float VolumeMultiplier;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float PitchMultiplier;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float StartTime;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UObject* WorldContextObject;

	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* SoundFire;

	UPROPERTY(EditAnywhere, Category = "Advance")
	AActor* OwningActor;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* fireparticle = nullptr;

	UPROPERTY(EditAnywhere, Category = "Advance")
	bool bIsUISound;
	void fire();
	void fireAB();

	void UpdateeventOnAbilityTime();
	
	//high for chek The tank is not the other way around
	float ZCoordinate1;
	float ZCoordinate;
};
