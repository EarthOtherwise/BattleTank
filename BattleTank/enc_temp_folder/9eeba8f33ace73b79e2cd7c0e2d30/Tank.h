// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTank_Nav_Move_Comp;
class ATank_Shot;
class UTankBarrel;
class UTank_Turret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTank_Turret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* AimComp;

	UPROPERTY(BlueprintReadOnly)
		UTank_Nav_Move_Comp* MoveComp;
	
	UTank_Turret* Turret;
	
	UTankBarrel* Barrel;
};
