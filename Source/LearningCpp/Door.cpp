// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = m_doorMesh;

	m_closeTime = 3.0f;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	m_originRotation = GetActorRotation();
	GetWorldTimerManager().SetTimer(m_doorTimerHandle,this, &ADoor::Open, 0.03f, true);
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_doorDeltaTime += DeltaTime;
}

void ADoor::Open()
{
	if (!bOpen)
	{
		bOpen = true;
		m_doorDeltaTime = 0.0f;
	}

	FRotator _rotation = GetActorRotation();
	_rotation = m_originRotation + FRotator(0.0f, FMath::Lerp(0.0f, 90.0f, m_doorDeltaTime), 0.0f);
	SetActorRotation(_rotation);
	if (m_doorDeltaTime > 1.0f)
	{
		GetWorldTimerManager().ClearTimer(m_doorTimerHandle);
		GetWorldTimerManager().SetTimer(m_doorTimerHandle, this, &ADoor::Close, 0.03f, true, m_closeTime);
	}
}

void ADoor::Close()
{
	if (bOpen)
	{
		bOpen = false;
		m_doorDeltaTime = 0.0f;
	}

	FRotator _rotation = GetActorRotation();
	_rotation = m_originRotation + FRotator(0.0f, FMath::Lerp(90.0f, 0.0f, m_doorDeltaTime), 0.0f);
	SetActorRotation(_rotation);
	if (m_doorDeltaTime > 1.0f)
	{
		GetWorldTimerManager().ClearTimer(m_doorTimerHandle);
	}
}

