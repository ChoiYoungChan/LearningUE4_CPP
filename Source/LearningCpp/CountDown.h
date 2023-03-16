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
	// �ּ��� �޸� Editor������ �� �� �ִ�
	UPROPERTY(EditAnywhere) int32 m_countdownTime;

	UTextRenderComponent* m_countdownText;

	void UpdateTimerDisplay();

	// Ÿ�̸Ӱ� ���ư��鼭 ȣ��Ǵ� �Լ�
	void AdvanceTimer();

	// AdvanceTimer�� Timer��ŭ �۵��� ���� ������ ó���� �ϱ� ���� �Լ�
	UFUNCTION(BlueprintNativeEvent) void CountdownHasFinished();

	virtual void CountdownHasFinished_Implementation();

	// Timer�� �����ϱ� ���� ����ü�� Countdown�� ���� �� Timer�� ���̻� �۵������ʰ� �ϱ� ���� �Լ�
	FTimerHandle _countdownTimerHandle;

};
