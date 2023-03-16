// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class LEARNINGCPP_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)	UStaticMeshComponent* m_doorMesh;

	UPROPERTY(EditAnywhere) float m_closeTime;

	float m_doorDeltaTime;

	bool bOpen;

	FTimerHandle m_doorTimerHandle;

	FRotator m_originRotation;

	void Open();

	void Close();
};
