// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

// Sets default values
AMovingActor::AMovingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_timer += DeltaTime;

	FVector _new_loc = GetActorLocation();
	_new_loc.Y += FMath::Cos(m_timer);
	SetActorLocation(_new_loc);
}

