// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomStruct.generated.h"

/**
 * 
 */
class LEARNINGCPP_API customStruct
{
public:
	customStruct();
	~customStruct();
};

// Atomic - 이 단위로 항상 직렬화됨을 의미
// BlueprintType - 이 구조체가 블루프린트에서 사용가능을 의미
// 만약 Editor에서만 사용하게 하려면 아래의 BlueprintType과 BlueprintReadWrite를 삭제
// 반대로 Blueprint에서만 사용하게 하려면 Atomic, EditAnywhere를 삭제

USTRUCT(Atomic, BlueprintType)
struct FCustomStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	AActor* m_actor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	int32 m_count;
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	float m_speed;
};
