// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/Tank_Track.h"
#include "Components/PrimitiveComponent.h"

void UTank_Track::SetThrottle(float NewThrottle)
{
	CurrentSetThrottle = FMath::Clamp<float>(NewThrottle, -0.5f, 1.f);

	FVector ForceApplied = GetForwardVector() * CurrentSetThrottle * TrackMaxDrivingForce;

	FVector ForceLocation = GetComponentLocation();

	Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent())->AddForceAtLocation(ForceApplied, ForceLocation);
}