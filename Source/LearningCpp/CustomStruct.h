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

// Atomic - �� ������ �׻� ����ȭ���� �ǹ�
// BlueprintType - �� ����ü�� �������Ʈ���� ��밡���� �ǹ�
// ���� Editor������ ����ϰ� �Ϸ��� �Ʒ��� BlueprintType�� BlueprintReadWrite�� ����
// �ݴ�� Blueprint������ ����ϰ� �Ϸ��� Atomic, EditAnywhere�� ����

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
