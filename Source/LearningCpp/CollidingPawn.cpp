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

	// USphereComponent구체의 물리처리를 하는 컴포넌트, 충돌만 처리하며 실체를 가지고 있지는 않다.
	USphereComponent* _SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = _SphereComponent;
	_SphereComponent->InitSphereRadius(40.0f);
	_SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// 실체를 추가
	UStaticMeshComponent* _SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepressentation"));
	_SphereVisual->SetupAttachment(RootComponent);
	// 에셋을 찾아서 불러오기
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereVisualAsset(TEXT("/Game/StarterContent/Shapers/Shape_Sphere.Shape_Sphere"));

	// 불러오는데 성공하면 메쉬와 위치 스케일을 설정
	if (SphereVisualAsset.Succeeded())
	{
		_SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		_SphereVisual->SetRelativeLocation(FVector(0,0,-40.0f));
		_SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	m_OurParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("OurParticleSystem"));
	// attachment설정
	m_OurParticleSystem->SetupAttachment(RootComponent);
	// 자동으로 실행하는것을 설정
	m_OurParticleSystem->bAutoActivate = false;
	// 파티클의 위치를 조정
	m_OurParticleSystem->SetRelativeLocation(FVector(-20.0f, 0, 20.0f));
	//
	static ConstructorHelpers::FObjectFinder<UParticleSystem>_ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Fire.P_Fire"));
	if (_ParticleAsset.Succeeded())
	{
		m_OurParticleSystem->SetTemplate(_ParticleAsset.Object);
	}

	// 카메라가 유저보다 약간 느리게 따라가는 기능과 벽을 뚫고 가지 않게 하는 기능을 제공
	USpringArmComponent* _SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraAttachmentArm");
	_SpringArm->SetupAttachment(RootComponent);
	// RelativeRotation으로 하면 에러가 뜨니 SetRelativeRotation을 앞으로 이용할 것
	_SpringArm->SetRelativeRotation(FRotator(-45.0f, 0, 0));
	// 따라가야할 타겟과의 거리를 설정
	_SpringArm->TargetArmLength = 400.0f;
	// 타겟보다 느리게 갈 것인지를 설정
	_SpringArm->bEnableCameraLag = true;
	// 카메라 속도를 설정
	_SpringArm->CameraLagSpeed = 3.0f;

	UCameraComponent* _Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	// SetupAttachment의 뒤에 USpringArmComponent::SocketName를 넣으면 카메라를 USpringArm에 내장된 소켓에 붙일 수 있다.
	_Camera->SetupAttachment(_SpringArm, USpringArmComponent::SocketName);

	m_OurMovemetComponent = CreateDefaultSubobject<UCollidingPawnMovementComponent>(TEXT("m_OurMovemetComponent"));
	m_OurMovemetComponent->UpdatedComponent = RootComponent;

	// 이 폰을 기본플레이어가 조종할 수 있게 설정
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