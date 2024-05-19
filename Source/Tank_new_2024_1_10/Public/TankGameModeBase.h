// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Tank_new_2024_1_10GameModeBase.h"
#include "TankGameModeBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyTextCunter, int32, EnemyCurrent, int32, EnemyDeafultCunt);

UCLASS()
class TANK_NEW_2024_1_10_API ATankGameModeBase : public ATank_new_2024_1_10GameModeBase
{
	GENERATED_BODY()

public:
	ATankGameModeBase();

	virtual void BeginPlay() override;

	int EnemyDie();

	FEnemyTextCunter OnChangeEnemyDie;

	void EventEnemy();

	UPROPERTY(EditAnywhere, Category = "Advance", BlueprintReadWrite)
	int EnemyCurrent;

private:
	void Tank_TopDown_White();

	UFUNCTION(BlueprintCallable)
	void winer();

	UFUNCTION(BlueprintCallable)
	int EnemyCurrentBLuprintcall(int EnemyCurrentBluprint);


	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class ATank_TopDown>Tank_TopDown;

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class ATank_TopDown>Tank_TopDown1;

	UPROPERTY(EditAnywhere, Category = "Advance")
	int EnemyDeafultCunt;

	

	UPROPERTY(EditAnywhere, Category = "Advance")
	TSubclassOf<class UUserWidget>Win;
};
