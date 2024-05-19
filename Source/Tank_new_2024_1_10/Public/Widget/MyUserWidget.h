// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"


/**
 * 
 */
UCLASS()
class TANK_NEW_2024_1_10_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UMyUserWidget(const FObjectInitializer& ObjectInitializer);

	virtual bool Initialize() override;

private:

	UFUNCTION()
	void OnpauseClick();

	UFUNCTION()
	void OnHealthChange(float health);

	UFUNCTION()
	void eventOnAbilityTime(float FirerateAB);

	UFUNCTION()
	void EnemyDie(int EnemyCurrent,int EnemyDeafultCunt);

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* Health_progress = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* AbulletAB = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Enemy_Counter=nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* pause=nullptr;

	TSubclassOf<class UNew_Pause> PauseMenuClass;

	FText enemiestext;
};
