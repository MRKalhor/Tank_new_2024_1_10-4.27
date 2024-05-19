// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "New_Pause.generated.h"

/**
 * 
 */
UCLASS()
class TANK_NEW_2024_1_10_API UNew_Pause : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual bool Initialize() override;

private:
	UFUNCTION(BlueprintCallable)
	void tankquite();

	UFUNCTION(BlueprintCallable)

	void ResumeGame();

	UPROPERTY(meta = (BindWidget))
	class UButton* Resume = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* Option = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* Quite = nullptr;

	
};



