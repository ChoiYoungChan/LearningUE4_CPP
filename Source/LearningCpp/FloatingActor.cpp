// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_speed = FVector(1.0f, 1.0f, 1.0f);
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// FVector - 언리얼에서 위치와 속도를 다루기 위한 타입
	FVector _new_location = GetActorLocation();

	// SIn(이동시간 + deltatime) 과 Sin(이동시간)의 차를 구함으로서 이동시간동안 높낮이를 구할 수 있다.
	float _deltaX = (FMath::Sin(m_runningTime.X + DeltaTime * m_speed.X) - FMath::Sin(m_runningTime.X));
	float _deltaY = (FMath::Sin(m_runningTime.Y + DeltaTime * m_speed.Y) - FMath::Sin(m_runningTime.Y));
	float _deltaZ = (FMath::Sin(m_runningTime.Z + DeltaTime * m_speed.Z) - FMath::Sin(m_runningTime.Z));
	
	_new_location += FVector(_deltaX, _deltaY, _deltaZ) * 20.0f;
	m_runningTime += DeltaTime * m_speed;

	SetActorLocation(_new_location);
}

