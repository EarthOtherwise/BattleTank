// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Public/Tank.h"

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

public:

  ATank* GetControlledTank() const;
};
