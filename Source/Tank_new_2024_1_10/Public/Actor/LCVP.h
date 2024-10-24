// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LCVP.generated.h"

UCLASS()
class TANK_NEW_2024_1_10_API ALCVP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALCVP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY( Category = "Advance",EditAnywhere,BlueprintReadWrite)
	bool Ereturn = false;

	UPROPERTY(EditAnywhere, Category = "Advance", BlueprintReadWrite)
	UStaticMeshComponent* LCVP;

	UPROPERTY(EditAnywhere, Category = "Advance", BlueprintReadWrite)
	UStaticMeshComponent* door;

private:

	UPROPERTY(EditAnywhere, Category = "Advance")
	class UBoxComponent* trigger;

	virtual void NotifyActorBeginOverlap(AActor* otherActor)override;

	virtual void NotifyActorEndOverlap(AActor* otherActor)override;

};
