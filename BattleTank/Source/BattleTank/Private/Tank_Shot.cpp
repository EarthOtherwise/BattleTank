// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank_Shot.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ATank_Shot::ATank_Shot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjMvmnt = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ShotMoveComp"));
	ProjMvmnt->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ATank_Shot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank_Shot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATank_Shot::Shoot(float Speed)
{
	ProjMvmnt->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjMvmnt->Activate();
}