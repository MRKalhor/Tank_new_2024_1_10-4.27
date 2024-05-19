// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/MainMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Pawn_Tank.h"




bool UMainMenu::Initialize()
{
	
	bool bSuccess = Super::Initialize();
	if (!bSuccess) { return false; }


	/*Singleplayer->OnClicked.AddDynamic(this, &UMainMenu::CallSingleplayer);


	Exit->OnClicked.AddDynamic(this, &UMainMenu::CallExit);*/



	return true;
}

void UMainMenu::BeginPlay()
{
	Singleplayer->OnClicked.AddDynamic(this, &UMainMenu::CallSingleplayer);


	Exit->OnClicked.AddDynamic(this, &UMainMenu::CallExit);
	

}

void UMainMenu::CallSingleplayer()
{
}

void UMainMenu::CallMultiplayer()
{
}

void UMainMenu::CallOption()
{
}

void UMainMenu::CallExit()
{
	//UE_LOG(LogTemp, Display, TEXT("MainMenu: Exit Called"));
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("Quit");
	
}



