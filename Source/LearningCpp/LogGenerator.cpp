// Fill out your copyright notice in the Description page of Project Settings.


#include "LogGenerator.h"
#include "LearningCpp.h"

// Sets default values
ALogGenerator::ALogGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALogGenerator::BeginPlay()
{
	Super::BeginPlay();
	// Fatal : 로그로 항상 콘솔 및 로그 파일에 출력되며 로그가 비활성화된 상태에서도 모든 작동을 중단
	//		   매우 치명적인 상황에 사용(충돌 리포트 띄워짐)
	// Error : 콘솔 및 로그 파일에 빨간색으로 출력
	// Warning : 콘솔 및 로그 파일에 노란색으로 출력
	// Display : 콘솔 및 로그 파일에 출력
	// Log : 로그파일과 에디터 출력 패널에는 출력되지만 게임 내 콘솔에서는 출력되지 않음
	// Verbose : 로그파일에는 출력되지만 게임 내 콘솔에서는 출력안됨, 자세한 로깅 및 디버깅에 사용
	// VeryVerbose : 로그파일에는 출력되지만 게임 내 콘솔에서는 출력안됨, 대락의 로그를 출력하는 상세한 로깅에 사용


	UE_LOG(LogTemp, Display, TEXT("Display"));
	UE_LOG(LogTemp, Error, TEXT("Error"));
	UE_LOG(LogTemp, Warning, TEXT("Warning"));

	// 여기서 %s는 포인터를 받기 때문에 포인터 형식으로 주소를 넣는 방식이 기존의 C++와 다른점
	FString _text = TEXT("FString text data");
	UE_LOG(LogTemp, Warning, TEXT("Test Textdata Log = %s"), *_text);

	// bool은 지정 형식이 없기 때문에 삼항연산자를 이용하여 출력
	bool _isActive = true;
	UE_LOG(LogTemp, Log, TEXT("Test Textdata Log = %s"), _isActive ? TEXT("true") : TEXT("false"));
	
	int _hp = 100;
	UE_LOG(LogTemp, Log, TEXT("HP = %d"), _hp);

	float _attackerSpeed = 1.0f;
	UE_LOG(LogTemp, Log, TEXT("Speed = %f"), _attackerSpeed);

	FVector _localLocation = GetActorLocation();
	UE_LOG(LogTemp, Log, TEXT("Location = %s"), *_localLocation.ToString());
	UE_LOG(LogTemp, Error, TEXT("Character Data = %s, HP = %d, Speed = %f, Loc = %s"), *_text, _hp,_attackerSpeed, *_localLocation.ToString());

	FString _testData = TEXT("FString text data");
	UE_LOG(LogTemp, Log, TEXT("Test Textdata Log = %s"), *_testData);
	UE_LOG(CustomLogCategory, Display, TEXT("CustomLogCategory"));
}

// Called every frame
void ALogGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

