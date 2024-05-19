// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TANK_NEW_2024_1_10_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

	virtual void BeginPlay();

	UFUNCTION(BlueprintCallable)
	void CallSingleplayer();

	UFUNCTION(BlueprintCallable)
	void CallMultiplayer();

	UFUNCTION(BlueprintCallable)
	void CallOption();

	UFUNCTION(BlueprintCallable)
	void CallExit();

	UPROPERTY(meta = (BindWidget))
	class UButton* Singleplayer = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* Multiplayer= nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* Option = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* Exit = nullptr;

	UPROPERTY(EditAnywhere, Category = "Advance")
	USoundBase* SoundMainmenu;
};
