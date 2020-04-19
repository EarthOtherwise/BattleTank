// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	float Speed = FMath::Clamp<float>(DegreesPerSecond, MinElevationSpeed, MaxElevationSpeed);

	float ElevationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;

	float NewElevation = FMath::Clamp<float>(RawNewElevation, MinBarrelPitchDegrees, MaxBarrelPitchDegrees);

	//SetRelativeRotation(FRotator(NewElevation, 0, 0));
}