// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/Tank_AIController.h"

ATank* ATank_AIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATank_AIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATank_AIController::BeginPlay()
{
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//Error
	}

	ATank* PlayerTankPawn = GetPlayerTank();
	if (PlayerTankPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found tank %s"),
			*GetPlayerTank()->GetHumanReadableName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find the player's tank"));
	}
}