// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class LEARNINGCPP_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	// UPROPERTY�� �ش� ������ Editor�׸��� �������Ʈ���� ����� �� �ְ�/������ �ְ� �ϴ� ����
	// EditAnywhere ��𼭵� ���ٰ����ϰ��ϴ� ����
	// BlueprintReadOnly �������Ʈ������ �б⸸ �����ϰ��ϴ� ����
	// BlueprintReadWrite �������Ʈ���� ���� �����ϰ� �ϴ� ����
	// VisibleAnywhere ���̱⸸ �ϰ� ������ �Ұ����ϰ� �ϴ� ����
	// Transient �ֹ߼����� ����, �������� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") int32 m_TotalDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage") float m_MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Damage") bool m_isAttackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") bool m_isEngague;

	// UFUNCTION�� �ش� �Լ��� �������Ʈ���� ����� ���ְ� �ϴ� ����
	// BlueprintCallable�������Ʈ���� ȣ�Ⱑ���� ���� ���α׷��Ӱ� ���� ����� �����̳ʰ� ����� �� ���
	// BlueprintImplementableEvent �������Ʈ���� ������ ����� cpp���� ȣ���ϴ� ���, ���α׷��Ӱ� �Լ� ���θ� ������ �ʿ���� �׳� �Լ� ȣ��
	// BlueprintNativeEvent cpp�� �������Ʈ ���ʿ��� ��� ������ �����ϵ��� �ϴ� ����
	// callfrom cpp�̺�Ʈ�� �θ� callfrom cpp�̺�Ʈ�� ������ ����ϸ� cpp, �������Ʈ ���� �� ȣ�� �� �� �ִ�.
	UFUNCTION(BlueprintCallable, Category = "Damage") void SetAttackable(bool isActive);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// ������Ʈ �ʱ�ȭ�� ȣ��Ǵ� �Լ�
	virtual void PostInitProperties() override;

	// ������Ʈ�� ������Ƽ�� �����ɶ� ȣ��Ǵ� �Լ�
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
