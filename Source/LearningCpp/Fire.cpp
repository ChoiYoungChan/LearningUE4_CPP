// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"

// Sets default values
AFire::AFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_fireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));
	RootComponent = m_fireParticle;

	m_fireTime = 5;
}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(m_fireTimerHandle, this, &AFire::Combustion, 1.0f, true);
}

// Called every frame
void AFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFire::Combustion()
{
	--m_fireTime;
	if (m_fireTime <= 0)
	{
		OffFIre();
	}
}

void AFire::OffFIre()
{
	// 타이머를 중단시키기
	GetWorldTimerManager().ClearTimer(m_fireTimerHandle);
	// Fire Particle을 비활성화 시키기
	m_fireParticle->DeactivateSystem();
}

