// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/Enemy_Health_Bar.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ProgressBar.h"
#include "Blueprint/UserWidget.h"
#include "Tank_TopDown.h"
#include "UObject/ConstructorHelpers.h"
#include "Tank_TopDown.h"


bool UEnemy_Health_Bar::Initialize()
{
    bool bSuccess = Super::Initialize();
    if (!bSuccess) { return false; }

    Enemy_Health_Bar->SetVisibility(ESlateVisibility::Hidden);

    AActor* ThisIs = this->GetOwningPlayerPawn();

    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATank_TopDown::StaticClass(), FoundActors);

    for (AActor* FoundActor : FoundActors)
    {
        ATank_TopDown* TankActor = Cast<ATank_TopDown>(FoundActor);
        if (TankActor)
        {
            UE_LOG(LogTemp, Warning, TEXT("Enemy Health bar : TankActor "));

            if (ThisIs)
            {
                TankActor->connectenemyhealth.AddDynamic(this, &UEnemy_Health_Bar::connectenemyhealth);
                UE_LOG(LogTemp, Warning, TEXT("Enemy Health bar : AddDynamic "));
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Enemy Health bar : AddDynamic Failed"));
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Enemy Health bar : (AActor* FoundActor : FoundActors) Failed "));
        }
    }

    if (UEnemy_Health_Bar* player = Cast<UEnemy_Health_Bar>(enemysub))
    {
        //ONEnemyHealthBar.AddDynamic(this, &UEnemy_Health_Bar::EVENT_ON_EnemyHealthBar);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Enemy Health bar : ONEnemyHealthBar.AddDynamic (Failed)"));

    }
       


    
    return true;
}


void UEnemy_Health_Bar::Tick(FGeometry MyGeometry, float InDeltaTime)
{
	
}



void UEnemy_Health_Bar::EVENT_ON_EnemyHealthBar()
{
}

void UEnemy_Health_Bar::connectenemyhealth(float health)
{
	float currenthealthpercent = health / 100;
    Enemy_Health_Bar->SetVisibility(Visibility);

	Enemy_Health_Bar->SetPercent(currenthealthpercent);
	UE_LOG(LogTemp, Warning, TEXT("Enemy Health bar :currenthealthpercent=%f "), currenthealthpercent);
}

float UEnemy_Health_Bar::LockAtTargetsss(FVector playerLocation)
{
    return 0;
}
