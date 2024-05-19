// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"
#include "Tank_TopDown.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"


ATankGameModeBase::ATankGameModeBase()
{
	ConstructorHelpers::FClassFinder<ATank_TopDown>Enemy1(TEXT("/Game/Character/BpTank_TopDown"));
	ConstructorHelpers::FClassFinder<ATank_TopDown>Enemy2(TEXT("/Game/Character/BpTank_TopDown1"));
	if (Enemy1.Class)
	{
		Tank_TopDown = Enemy1.Class;
	}
	if (Enemy2.Class)
	{
		Tank_TopDown1 = Enemy2.Class;
	}
}

void ATankGameModeBase::BeginPlay()
{
	OnChangeEnemyDie.Broadcast(EnemyCurrent, EnemyDeafultCunt);
	Super::BeginPlay();

	TArray<AActor*>Enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Tank_TopDown, Enemies);

	EnemyDeafultCunt += Enemies.Num();
	Tank_TopDown_White();

	EnemyCurrent = EnemyDeafultCunt;
}

int ATankGameModeBase::EnemyDie()
{
	EnemyCurrent--;
	if (EnemyCurrent==0)
	{
		winer();
	}
	EventEnemy();
	return 0;
}

void ATankGameModeBase::EventEnemy()
{
	OnChangeEnemyDie.Broadcast(EnemyCurrent, EnemyDeafultCunt);
}

void ATankGameModeBase::Tank_TopDown_White()
{
	TArray<AActor*>Enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Tank_TopDown1, Enemies);

	EnemyDeafultCunt += Enemies.Num();
}

void ATankGameModeBase::winer()
{
	
	if (Win)
	{
		UUserWidget* createwin = CreateWidget<UUserWidget>(GetWorld(), Win, FName("Win widget"));
		createwin->AddToViewport();
		UE_LOG(LogTemp, Warning, TEXT("Tnakgamemodebase : Win Called"))
	}
	else { UE_LOG(LogTemp, Warning, TEXT("Tnakgamemodebase : Win empity")) }

	UGameplayStatics::SetGlobalTimeDilation(this, 0);
	GetWorld()->GetFirstPlayerController()->DisableInput(GetWorld()->GetFirstPlayerController());

}
// ???? ??? ??? EnemyCurren ?? ????????

int ATankGameModeBase::EnemyCurrentBLuprintcall(int EnemyCurrentBluprint)
{
	EnemyCurrentBluprint=EnemyCurrent;
	return EnemyCurrentBluprint;
}
