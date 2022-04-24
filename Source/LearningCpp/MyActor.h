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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage") int32 m_TotalDamage;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "Damage") float m_MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Damage") bool m_isAttackable;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
