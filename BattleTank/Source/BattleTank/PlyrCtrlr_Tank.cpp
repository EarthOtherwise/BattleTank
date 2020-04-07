// Fill out your copyright notice in the Description page of Project Settings.


#include "PlyrCtrlr_Tank.h"

ATank* APlyrCtrlr_Tank::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}