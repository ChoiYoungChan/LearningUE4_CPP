// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Components/TextRenderComponent.h>
#include "CountDown.generated.h"


UCLASS()
class LEARNINGCPP_API ACountDown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// 주석을 달면 Editor에서도 볼 수 있다
	UPROPERTY(EditAnywhere) int32 m_countdownTime;

	UTextRenderComponent* m_countdownText;

	void UpdateTimerDisplay();

	// 타이머가 돌아가면서 호출되는 함수
	void AdvanceTimer();

	// AdvanceTimer가 Timer만큼 작동한 이후 마무리 처리를 하기 위한 함수
	UFUNCTION(BlueprintNativeEvent) void CountdownHasFinished();

	virtual void CountdownHasFinished_Implementation();

	// Timer를 조작하기 위한 구조체로 Countdown이 끝난 후 Timer가 더이상 작동되지않게 하기 위한 함수
	FTimerHandle _countdownTimerHandle;

};
