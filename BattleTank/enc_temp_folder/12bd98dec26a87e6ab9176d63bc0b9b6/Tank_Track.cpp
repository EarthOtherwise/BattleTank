// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/Tank_Track.h"
#include "Components/PrimitiveComponent.h"

void UTank_Track::SetThrottle(float NewThrottle)
{
	CurrentSetThrottle = FMath::Clamp<float>(NewThrottle, -0.5f, 1.f);
}

void UTank_Track::ThrottleChange(bool PlusOrMinus)
{
	UE_LOG(LogTemp, Warning, TEXT("track throttle"));
	
	float NewThrottle;
	if (PlusOrMinus)
	{
		NewThrottle = CurrentSetThrottle + ThrottleIncrement;
	}
	else
	{
		NewThrottle = CurrentSetThrottle - ThrottleIncrement;
	}

	UE_LOG(LogTemp, Warning, TEXT("current throttle: %f"), 
		NewThrottle);
	SetThrottle(NewThrottle);
}

void UTank_Track::ApplyThrottle()
{
	FVector ForceApplied = GetForwardVector() * CurrentSetThrottle * TrackMaxDrivingForce;

	UE_LOG(LogTemp, Warning, TEXT("current Force: %f"),
		ForceApplied.Size());

	FVector ForceLocation = GetComponentLocation();

	Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent())->AddForceAtLocation(ForceApplied, ForceLocation);
}