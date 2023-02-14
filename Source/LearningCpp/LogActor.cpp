// Fill out your copyright notice in the Description page of Project Settings.


#include "LogActor.h"
#include <kismet/KismetSystemLibrary.h>

// Sets default values
ALogActor::ALogActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALogActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Editor���� ��·α� �гο��� ��� �ȵ�
	// �� ó�� �Ű������� �ǹ� -1 �α׸� ������ ���� ������ , 1 �α׸� ����� ���� ����� ����
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("LogError"));

	// �������Ʈ���� ����ϴ� Print String�� ������
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("C++ Log"), true, true, FLinearColor::Green, 5.0f);
}

