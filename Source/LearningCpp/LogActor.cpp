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
	// Editor상의 출력로그 패널에는 출력 안됨
	// 맨 처음 매개변수의 의미 -1 로그를 다음줄 띄우고 계속출력 , 1 로그를 지우고 띄우고 지우고 띄우고
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("LogError"));

	// 블루프린트에서 출력하는 Print String과 동일함
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("C++ Log"), true, true, FLinearColor::Green, 5.0f);
}

