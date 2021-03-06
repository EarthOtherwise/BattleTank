// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTank_Turret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector WorldSpaceAim, float ShotSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTank_Turret* TurretToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UTankBarrel* Barrel = nullptr;

	void MoveBarrelToward(FVector FinalPosition);

	UTank_Turret* Turret = nullptr;

	void MoveTurretToward(FVector FinalPosition);
};
