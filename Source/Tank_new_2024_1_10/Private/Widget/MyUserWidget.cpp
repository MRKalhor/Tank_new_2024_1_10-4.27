// Fill out your copyright notice in the Description page of Project Settings.

#include "Widget/MyUserWidget.h"
#include "Components/Button.h"
#include "widget/New_Pause.h"
#include "Components/TextBlock.h"


#include "UObject/ConstructorHelpers.h"
#include "Pawn_Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ProgressBar.h"
#include "TankGameModeBase.h"

#define LOCTEXT_NAMESPACE "UpdateText"


UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
	//Get Pause Menu Class Reference

	ConstructorHelpers::FClassFinder<UNew_Pause>PauseMenuReference(TEXT("/Game/Widget/BP_PauseMenu"));
		
		if (!PauseMenuReference.Class)
		{
			UE_LOG(LogTemp, Warning, TEXT("HUD : Cant Find pause menu refrence"))
				return;
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("HUD : Find pause menu refrence"))
	//Fill Pause Menu Class Variable
			PauseMenuClass = PauseMenuReference.Class;
}

bool UMyUserWidget::Initialize()
{

	bool bSuccess = Super::Initialize();

	if (!bSuccess) { return false; }

	pause->OnClicked.AddDynamic(this, &UMyUserWidget::OnpauseClick);//برای وقتی کیلک شد یه اتفاقی بیوفته (ایونت کلیک)

	if (APawn_Tank* player=Cast<APawn_Tank>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		player->OnHealthChange.AddDynamic(this, &UMyUserWidget::OnHealthChange);
	}

	if (APawn_Tank* player = Cast<APawn_Tank>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		player->eventOnAbilityTime.AddDynamic(this, &UMyUserWidget::eventOnAbilityTime);
	}

	

	//access to gamemod
	auto gamemode=UGameplayStatics::GetGameMode(this);
	if (gamemode)
	{
		UE_LOG(LogTemp, Warning, TEXT("HUD : Find gamemode "))

		ATankGameModeBase* ATankGameMode = Cast<ATankGameModeBase>(gamemode);
		if (ATankGameMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("HUD : Find ATankGameMode "))

			ATankGameMode->OnChangeEnemyDie.AddDynamic(this, &UMyUserWidget::EnemyDie);
			ATankGameMode->EventEnemy();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HUD : cant Find ATankGameMode "))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HUD : cant Find gamemode "))
	}
	
	return true;

}

void UMyUserWidget::OnpauseClick()
{
	
	UE_LOG(LogTemp, Warning, TEXT("HUD :Pause Clicked"));
	
	// TODO show Pause Menu
	if (!PauseMenuClass)return;

	UGameplayStatics::SetGlobalTimeDilation(this, 0);
	GetWorld()->GetFirstPlayerController()->DisableInput(GetWorld()->GetFirstPlayerController());


	UNew_Pause* createdpausemenu = CreateWidget<UNew_Pause>(GetWorld(), PauseMenuClass, FName("Pause menu widget"));

	if (createdpausemenu)
	{
		UE_LOG(LogTemp, Warning, TEXT("HUD :  Find createdpausemenu"));
		createdpausemenu->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HUD :  cant Find createdpausemenu"));
		return;
	}
	
}

void UMyUserWidget::OnHealthChange(float health)
{
	float currenthealthpercent = health / 100;

	Health_progress->SetPercent(currenthealthpercent);
}

void UMyUserWidget::eventOnAbilityTime(float FirerateAB)
{
	float FirerateABpercent = FirerateAB / 20;
	AbulletAB->SetPercent(FirerateABpercent);
}

void UMyUserWidget::EnemyDie(int EnemyCurrent, int EnemyDeafultCunt)
{
	enemiestext = FText::Format(LOCTEXT("UpdateText", "{0}/{1}"), EnemyDeafultCunt, EnemyCurrent);

		Enemy_Counter->SetText(enemiestext);
}

