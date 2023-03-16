// Fill out your copyright notice in the Description page of Project Settings.


#include "CountDown.h"

// Sets default values
ACountDown::ACountDown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	m_countdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Timer"));
	// ������ �Ǵ� �ؽ�Ʈ�� ����� ����
	m_countdownText->SetHorizontalAlignment(EHTA_Center);
	// ũ�⸦ �����ϱ�
	m_countdownText->SetWorldSize(150.0f);
	// RootComponent�� ������ֱ�
	RootComponent = m_countdownText;

	m_countdownTime = 3;
}

// Called when the game starts or when spawned
void ACountDown::BeginPlay()
{
	Super::BeginPlay();
	UpdateTimerDisplay();

	GetWorldTimerManager().SetTimer(_countdownTimerHandle, this, &ACountDown::AdvanceTimer, 1.0f, true);
}

void ACountDown::UpdateTimerDisplay()
{
	m_countdownText->SetText(FString::FromInt(FMath::Max(m_countdownTime, 0)));
}

void ACountDown::AdvanceTimer()
{
	--m_countdownTime;
	UpdateTimerDisplay();

	if (m_countdownTime < 0)
	{
		GetWorldTimerManager().ClearTimer(_countdownTimerHandle);
		CountdownHasFinished();
	}
}

void ACountDown::CountdownHasFinished_Implementation()
{
	m_countdownText->SetText(TEXT("----------"));
}

