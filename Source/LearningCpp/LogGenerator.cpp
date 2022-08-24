// Fill out your copyright notice in the Description page of Project Settings.


#include "LogGenerator.h"

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
}

// Called every frame
void ALogGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

