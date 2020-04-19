// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/TankAimingComponent.h"
#include "BattleTank/Public/Tank_Turret.h"
#include "BattleTank/Public/TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::MoveBarrelToward(FVector FinalPosition)
{
	FRotator DeltaRotation(Barrel->GetForwardVector().Rotation() - FinalPosition.Rotation());

	Barrel->Elevate(DeltaRotation.Pitch);
}

void UTankAimingComponent::MoveTurretToward(FVector FinalPosition)
{
	FRotator DeltaRotation(Turret->GetForwardVector().Rotation() - FinalPosition.Rotation());

	Turret->Rotate(DeltaRotation.Yaw);
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTank_Turret* TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float ShotSpeed)
{
	if (Barrel && Turret)
	{
		FVector BarrelAimDirection;
		FVector BarrelTipLocation = Barrel->GetSocketLocation(FName("Projectile"));

		if (UGameplayStatics::SuggestProjectileVelocity(this, BarrelAimDirection,
			BarrelTipLocation, WorldSpaceAim, ShotSpeed, false, 0, 0,
			ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			MoveBarrelToward(BarrelAimDirection);
			MoveTurretToward(BarrelAimDirection);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No firing solution found"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error with barrel or turret"));
	}
}