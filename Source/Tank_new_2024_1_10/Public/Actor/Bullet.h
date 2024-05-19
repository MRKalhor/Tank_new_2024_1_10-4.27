// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class TANK_NEW_2024_1_10_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Advance")
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, Category = "Advance")
	class UProjectileMovementComponent* movmentcomponent;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<  UDamageType > DamageTypeClass; 

	UPROPERTY(EditAnywhere, Category = "Advance")
	float BaseDamage = 20;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem* bulletparticle;
	
	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* HitSound;
};
