// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/Tank_Turret.h"

void UTank_Turret::Rotate(float DegreesPerSecond)
{
	float Speed = FMath::Clamp<float>(DegreesPerSecond, MinRotationSpeed, MaxRotationSpeed);

	float RotationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewRotation = GetRelativeRotation().Yaw + RotationChange;

	//SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}