// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

// ����ü ���
// �𸮾󿡼��� ����ü�� �ټ� �ٸ� �����̴�, ���� �н��� ��

USTRUCT(Atomic, BlueprintType)
struct FChangeCameraData
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite) AActor* m_camera;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite) float m_time_between_camera_changes;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite) float m_sommth_blend_time;
};

UCLASS()
class LEARNINGCPP_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	 
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnyWhere) TArray<FChangeCameraData> m_camera_array;
	//UPROPERTY(EditAnyWhere) AActor* m_camera_1;
	//UPROPERTY(EditAnyWhere) AActor* m_camera_2;
	UPROPERTY(EditAnyWhere) float m_time_to_next_camera_change;

	int32 m_now_camera_index;
};
