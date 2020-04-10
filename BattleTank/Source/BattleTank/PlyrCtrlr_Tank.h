// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank/Public/Tank.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlyrCtrlr_Tank.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API APlyrCtrlr_Tank : public APlayerController
{
	GENERATED_BODY()

protected:

  virtual void BeginPlay() override;

public:

  virtual void Tick(float DeltaTime) override;

  ATank* GetControlledTank() const;

private:

  bool GetSightRayHitLocation(FVector &OUT_HitLocation);

  void AimTowardCrosshair();
};
