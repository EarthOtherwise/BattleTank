// Fill out your copyright notice in the Description page of Project Settings.


#include "PlyrCtrlr_Tank.h"

void APlyrCtrlr_Tank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

ATank* APlyrCtrlr_Tank::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

bool APlyrCtrlr_Tank::GetSightRayHitLocation(FVector& OUT_HitLocation)
{
	OUT_HitLocation = FVector(1.f);
	return true;
}

void APlyrCtrlr_Tank::AimTowardCrosshair()
{
	if (!GetControlledTank()){return;}

	FVector AimAtLocation;

	if (GetSightRayHitLocation(AimAtLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank is pointing at %s"),
			*AimAtLocation.ToString());
	}
}

void APlyrCtrlr_Tank::BeginPlay()
{
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//Error
	}
}