// Fill out your copyright notice in the Description page of Project Settings.


#include "RevolutionnSceneComponent.h"

// Sets default values for this component's properties
URevolutionnSceneComponent::URevolutionnSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	UStaticMeshComponent* m_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RevolutionMesh"));
	m_mesh->SetupAttachment(this);
	m_mesh->SetRelativeLocation(FVector(0, 100, 0));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> m_meshAssert(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (m_meshAssert.Succeeded())
	{
		m_mesh->SetStaticMesh(m_meshAssert.Object);
	}
}


// Called when the game starts
void URevolutionnSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URevolutionnSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FRotator m_rotation = GetComponentRotation();
	m_rotation.Yaw += DeltaTime * 100;
	SetWorldRotation(m_rotation);
}

