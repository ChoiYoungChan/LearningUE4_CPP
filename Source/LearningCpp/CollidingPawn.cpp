// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawn.h"
#include "CollidingPawnMovementComponent.h"
#include <Engine/Classes/Components/SphereComponent.h>
#include <Engine/Classes/Particles/ParticleSystemComponent.h>
#include <Engine/Classes/GameFramework/SpringArmComponent.h>
#include <Engine/Classes/Camera/CameraComponent.h>


// Sets default values
ACollidingPawn::ACollidingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// USphereComponent��ü�� ����ó���� �ϴ� ������Ʈ, �浹�� ó���ϸ� ��ü�� ������ ������ �ʴ�.
	USphereComponent* _SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = _SphereComponent;
	_SphereComponent->InitSphereRadius(40.0f);
	_SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// ��ü�� �߰�
	UStaticMeshComponent* _SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepressentation"));
	_SphereVisual->SetupAttachment(RootComponent);
	// ������ ã�Ƽ� �ҷ�����
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereVisualAsset(TEXT("/Game/StarterContent/Shapers/Shape_Sphere.Shape_Sphere"));

	// �ҷ����µ� �����ϸ� �޽��� ��ġ �������� ����
	if (SphereVisualAsset.Succeeded())
	{
		_SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		_SphereVisual->SetRelativeLocation(FVector(0,0,-40.0f));
		_SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	m_OurParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OurParticleSystem"));
	// attachment����
	m_OurParticleSystem->SetupAttachment(RootComponent);
	// �ڵ����� �����ϴ°��� ����
	m_OurParticleSystem->bAutoActivate = false;
	// ��ƼŬ�� ��ġ�� ����
	m_OurParticleSystem->SetRelativeLocation(FVector(-20.0f, 0, 20.0f));
	//
	static ConstructorHelpers::FObjectFinder<UParticleSystem>_ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (_ParticleAsset.Succeeded())
	{
		m_OurParticleSystem->SetTemplate(_ParticleAsset.Object);
	}

	// ī�޶� �������� �ణ ������ ���󰡴� ��ɰ� ���� �հ� ���� �ʰ� �ϴ� ����� ����
	USpringArmComponent* _SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraAttachmentArm");
	_SpringArm->SetupAttachment(RootComponent);
	// RelativeRotation���� �ϸ� ������ �ߴ� SetRelativeRotation�� ������ �̿��� ��
	_SpringArm->SetRelativeRotation(FRotator(-45.0f, 0, 0));
	// ���󰡾��� Ÿ�ٰ��� �Ÿ��� ����
	_SpringArm->TargetArmLength = 400.0f;
	// Ÿ�ٺ��� ������ �� �������� ����
	_SpringArm->bEnableCameraLag = true;
	// ī�޶� �ӵ��� ����
	_SpringArm->CameraLagSpeed = 3.0f;

	UCameraComponent* _Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	// SetupAttachment�� �ڿ� USpringArmComponent::SocketName�� ������ ī�޶� USpringArm�� ����� ���Ͽ� ���� �� �ִ�.
	_Camera->SetupAttachment(_SpringArm, USpringArmComponent::SocketName);

	m_OurMovemetComponent = CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("m_OurMovemetComponent"));
	m_OurMovemetComponent->UpdatedComponent = RootComponent;

	// �� ���� �⺻�÷��̾ ������ �� �ְ� ����
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACollidingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollidingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollidingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("ParticleToggle", IE_Pressed, this, &ACollidingPawn::ParticleToggle);
	InputComponent->BindAxis("MoveForward", this, &ACollidingPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACollidingPawn::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACollidingPawn::Turn);
}

UPawnMovementComponent* ACollidingPawn::GetMovementComponent() const
{
	return m_OurMovemetComponent;
}

void ACollidingPawn::MoveForward(float _axisValue)
{
	if (m_OurMovemetComponent && (m_OurMovemetComponent->UpdatedComponent == RootComponent)) {
		m_OurMovemetComponent->AddInputVector(GetActorForwardVector() * _axisValue);
	}
}

void ACollidingPawn::MoveRight(float _axisValue)
{
	if (m_OurMovemetComponent && (m_OurMovemetComponent->UpdatedComponent == RootComponent)) {
		m_OurMovemetComponent->AddInputVector(GetActorRightVector() * _axisValue);
	}
}

void ACollidingPawn::Turn(float _axisValue)
{
	FRotator _rotator = GetActorRotation();
	_rotator.Yaw += _axisValue;
	SetActorRotation(_rotator);
}

void ACollidingPawn::ParticleToggle()
{
	if (m_OurParticleSystem && m_OurParticleSystem->Template)
	{
		m_OurParticleSystem->ToggleActive();
	}
}