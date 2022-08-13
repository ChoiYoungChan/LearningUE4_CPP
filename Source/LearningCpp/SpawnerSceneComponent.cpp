// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerSceneComponent.h"

// Sets default values for this component's properties
USpawnerSceneComponent::USpawnerSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	for (int count = 0; count <3; count++)
	{
		UStaticMeshComponent* _child = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("child"), count));
		_child->SetupAttachment(this);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> _meshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
		if (_meshAsset.Succeeded())
		{
			_child->SetStaticMesh(_meshAsset.Object);
		}
		float radian = (2.0f * PI) / 3.0f;
		radian *= count;
		FVector _location = FVector(FMath::Cos(radian), FMath::Sin(radian), 0.0f) * 100;
		_child->SetRelativeLocation(_location);
		m_child.Add(_child);
	}

	m_destroyTime = 5.0f;
	// ...
}


// Called when the game starts
void USpawnerSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnerSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	m_destroyTime -= DeltaTime;
	if (m_destroyTime < 0.0f)
	{
		for (int count = 0; count < m_child.Num(); count++)
		{
			m_child[count]->DestroyComponent();
		}
		DestroyComponent();
	}
	// ...
}

