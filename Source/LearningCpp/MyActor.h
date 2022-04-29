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
	// UPROPERTY는 해당 변수를 Editor그리고 블루프린트에서 사용할 수 있게/볼수만 있게 하는 설정
	// EditAnywhere 어디서든 접근가능하게하는 설정
	// BlueprintReadOnly 블루프린트에서는 읽기만 가능하게하는 설정
	// BlueprintReadWrite 블루프린트에서 편집 가능하게 하는 설정
	// VisibleAnywhere 보이기만 하고 편집은 불가능하게 하는 설정
	// Transient 휘발성으로 설정, 저장하지 않음
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") int32 m_TotalDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage") float m_MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Damage") bool m_isAttackable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") bool m_isEngague;

	// UFUNCTION은 해당 함수를 블루프린트에서 사용할 수있게 하는 설정
	// BlueprintCallable블루프린트에서 호출가능한 설정 프로그래머가 만든 기능을 디자이너가 사용할 때 사용
	// BlueprintImplementableEvent 블루프린트에서 설정한 기능을 cpp에서 호출하는 방식, 프로그래머가 함수 내부를 지정할 필요없이 그냥 함수 호출
	// BlueprintNativeEvent cpp와 블루프린트 양쪽에서 기능 설정이 가능하도록 하는 설정
	// callfrom cpp이벤트와 부모 callfrom cpp이벤트를 적절히 사용하면 cpp, 블루프린트 양쪽 다 호출 할 수 있다.
	UFUNCTION(BlueprintCallable, Category = "Damage") void SetAttackable(bool isActive);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// 오브젝트 초기화시 호출되는 함수
	virtual void PostInitProperties() override;

	// 오프젝트의 프로퍼티가 수정될때 호출되는 함수
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
