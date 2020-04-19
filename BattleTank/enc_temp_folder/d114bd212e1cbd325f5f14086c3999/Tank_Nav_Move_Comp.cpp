// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank/Public/Tank_Nav_Move_Comp.h"

void UTank_Nav_Move_Comp::Intent_MoveParallel(float Throw)
{

}

void UTank_Nav_Move_Comp::Initialize(UTank_Track* Left, UTank_Track* Right)
{
	LeftTrack = Left;
	RightTrack = Right;
}