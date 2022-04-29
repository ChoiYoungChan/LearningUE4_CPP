// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_TotalDamage = 100;
	m_MoveSpeed = 5.0f;
	m_isEngague = false;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyActor::SetAttackable(bool isActive)
{
	m_isAttackable = isActive;
}

void AMyActor::PostInitProperties()
{
	Super::PostInitProperties();
	SetAttackable(m_isEngague);
}

void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	SetAttackable(m_isEngague);
	Super::PostEditChangeProperty(PropertyChangedEvent);
}



