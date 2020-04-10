// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank/Public/Tank.h"

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATank_AIController : public AAIController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
};
