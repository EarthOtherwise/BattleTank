// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Tank_Track.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTank_Track : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float NewThrottle);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void ThrottleChange (bool PlusOrMinus);

	UFUNCTION(BlueprintCallable, Category = "Throttle")
		void ApplyThrottle();

	float CurrentSetThrottle = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Throttle")
	float ThrottleIncrement = 0.3f;

	UPROPERTY(EditDefaultsOnly, Category = "Throttle")
		float TrackMaxDrivingForce = 40000000.f;

	bool UseSetThrottle = false;
};
