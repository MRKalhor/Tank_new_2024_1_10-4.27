// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TANK_NEW_2024_1_10_API AMyActor : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	virtual void NotifyActorBeginOverlap(AActor* otherActore)override;
	virtual void NotifyActorEndOverlap(AActor* otherActore)override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Editanywhere, Category = "Component")
	UStaticMeshComponent* meshcomponent;

	UPROPERTY(Editanywhere, Category = "Component")
	UStaticMeshComponent* meshcomponent2;

	UPROPERTY(Editanywhere, Category = "Component")
	class UBoxComponent* boxcomponent;

	//UPROPERTY(Editanywhere, Category = "Component")
	//AActor* Door = nullptr;

	//UPROPERTY(Editanywhere, Category = "AdvenceSeld")
	//TSubclassOf<class APawn_Tank>tankclass;

	/*UPROPERTY(EditAnywhere, Category = "Advance")
	float timer = 2;
	float time = 0;*/

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<  UDamageType > DamageTypeClass;

	UPROPERTY(EditAnywhere, Category = "Advance")
	float BaseDamage = 20;

	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* SoundBase;

	UPROPERTY(EditAnywhere, Category = "Advance")
	UParticleSystem *partialsystem;


};
