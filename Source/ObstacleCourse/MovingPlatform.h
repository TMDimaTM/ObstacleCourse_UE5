// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLECOURSE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category="Moving")
	FVector MoveVelocity = FVector(100, 0, 0);

	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 250;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity = FRotator(0, 180, 0);

	FVector StartLocation;
	FVector CurrentLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	float GetDistanceMoved() const;
	bool ShouldReturnPlatform() const;

};