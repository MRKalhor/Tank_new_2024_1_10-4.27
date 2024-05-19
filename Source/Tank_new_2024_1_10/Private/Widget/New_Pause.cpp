// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/New_Pause.h"
#include "Kismet/GameplayStatics.h"


bool UNew_Pause::Initialize()
{
	bool bSuccess = Super::Initialize();


	if (!bSuccess) { return false; }
	return true;
}

void UNew_Pause::tankquite()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("Quit");
}

void UNew_Pause::ResumeGame()
{
	UGameplayStatics::SetGlobalTimeDilation(this, 1);
	GetWorld()->GetFirstPlayerController()->EnableInput(GetWorld()->GetFirstPlayerController());

	RemoveFromParent();
}
