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
	// Fatal : �α׷� �׻� �ܼ� �� �α� ���Ͽ� ��µǸ� �αװ� ��Ȱ��ȭ�� ���¿����� ��� �۵��� �ߴ�
	//		   �ſ� ġ������ ��Ȳ�� ���(�浹 ����Ʈ �����)
	// Error : �ܼ� �� �α� ���Ͽ� ���������� ���
	// Warning : �ܼ� �� �α� ���Ͽ� ��������� ���
	// Display : �ܼ� �� �α� ���Ͽ� ���
	// Log : �α����ϰ� ������ ��� �гο��� ��µ����� ���� �� �ֿܼ����� ��µ��� ����
	// Verbose : �α����Ͽ��� ��µ����� ���� �� �ֿܼ����� ��¾ȵ�, �ڼ��� �α� �� ����뿡 ���
	// VeryVerbose : �α����Ͽ��� ��µ����� ���� �� �ֿܼ����� ��¾ȵ�, ����� �α׸� ����ϴ� ���� �α뿡 ���


	UE_LOG(LogTemp, Display, TEXT("Display"));
	UE_LOG(LogTemp, Error, TEXT("Error"));
	UE_LOG(LogTemp, Warning, TEXT("Warning"));

	// ���⼭ %s�� �����͸� �ޱ� ������ ������ �������� �ּҸ� �ִ� ����� ������ C++�� �ٸ���
	FString _text = TEXT("FString text data");
	UE_LOG(LogTemp, Warning, TEXT("Test Textdata Log = %s"), *_text);

	// bool�� ���� ������ ���� ������ ���׿����ڸ� �̿��Ͽ� ���
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

