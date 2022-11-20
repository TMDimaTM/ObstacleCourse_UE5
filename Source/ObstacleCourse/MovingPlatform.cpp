// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	CurrentLocation = StartLocation;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MoveVelocity.IsZero())
	{
		MovePlatform(DeltaTime);
	}
	if (!RotationVelocity.IsZero())
	{
		RotatePlatform(DeltaTime);
	}
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldReturnPlatform())
	{
		StartLocation = MoveVelocity.GetSafeNormal() * MoveDistance + StartLocation;
		SetActorLocation(StartLocation);
		MoveVelocity *= -1;
	}
	else
	{
		CurrentLocation = CurrentLocation + MoveVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Distance(StartLocation, CurrentLocation);
}

bool AMovingPlatform::ShouldReturnPlatform() const
{
	return GetDistanceMoved() >= MoveDistance;
}