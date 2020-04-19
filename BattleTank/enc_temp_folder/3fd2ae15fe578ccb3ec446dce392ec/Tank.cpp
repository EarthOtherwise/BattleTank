// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/Tank.h"
#include "BattleTank/Public/TankAimingComponent.h"
#include "BattleTank/Public/Tank_Nav_Move_Comp.h"
#include "BattleTank/Public/TankBarrel.h"
#include "BattleTank/Public/Tank_Turret.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	AimComp->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTank_Turret* TurretToSet)
{
	AimComp->SetTurretReference(TurretToSet);
}

void ATank::AimAt(FVector HitLocation)
{
}

void ATank::Fire()
{
}

