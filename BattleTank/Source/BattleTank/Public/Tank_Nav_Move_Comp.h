// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Tank_Nav_Move_Comp.generated.h"

class ATank;
class UTank_Track;

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTank_Nav_Move_Comp : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "FlyByWire")
		void Intent_MoveParallel(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTank_Track* Left, UTank_Track* Right);
protected:

	UPROPERTY(BlueprintReadOnly, Category = "FlyByWire")
	ATank* ControlledTank;

	UTank_Track* LeftTrack;
	UTank_Track* RightTrack;
};
