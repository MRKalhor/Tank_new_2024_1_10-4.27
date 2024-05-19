// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Enemy_Health_Bar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FON_EnemyHealthBar);
/**
 * 
 */
UCLASS()
class TANK_NEW_2024_1_10_API UEnemy_Health_Bar : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual bool Initialize() override;
	virtual void Tick(FGeometry MyGeometry, float InDeltaTime);
	UPROPERTY(EditAnywhere,meta = (BindWidget))
	class UProgressBar* Enemy_Health_Bar = nullptr;

	UPROPERTY(EditAnywhere, Category = "Advance")
	FON_EnemyHealthBar ONEnemyHealthBar;

	UFUNCTION()
	void EVENT_ON_EnemyHealthBar();

private:

	UFUNCTION()
	void connectenemyhealth(float health);

	UPROPERTY(EditAnywhere, Category = "Advance")
	float LockAtTargetss = 2000;

	UFUNCTION()
	float LockAtTargetsss(FVector playerLocation);

	FString ThisName;

	TSubclassOf<class UEnemy_Health_Bar> enemysub;
};

