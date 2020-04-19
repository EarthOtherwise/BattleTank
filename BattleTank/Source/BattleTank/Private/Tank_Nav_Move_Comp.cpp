// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/Tank_Nav_Move_Comp.h"
#include "BattleTank/Public/Tank_Track.h"

void UTank_Nav_Move_Comp::Intent_MoveParallel(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTank_Nav_Move_Comp::Initialize(UTank_Track* Left, UTank_Track* Right)
{
	if (!Left || !Right)
	{
		return;
	}
	LeftTrack = Left;
	RightTrack = Right;
}