// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Engine/Classes/Particles/ParticleSystemComponent.h>
#include "Fire.generated.h"

UCLASS()
class LEARNINGCPP_API AFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere) UParticleSystemComponent* m_fireParticle;

	UPROPERTY(EditAnywhere) int8 m_fireTime;

	FTimerHandle m_fireTimerHandle;

	void Combustion();

	UFUNCTION(BlueprintCallable) void OffFIre();
};
