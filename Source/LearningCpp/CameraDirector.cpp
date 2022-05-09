#include "CameraDirector.h"
#include <kismet/GameplayStatics.h>

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ���⼭ const�� ���� ���� -> �� ������ ����μ� �������� ���������� �����ϴ°�
	const float _time_between_camera_changes = 2.0f;
	const float _sommth_blend_time = 0.75f;

	m_time_to_next_camera_change -= DeltaTime;
	if (m_time_to_next_camera_change <= 0.0f) { 
		FChangeCameraData _now_camera = m_camera_array[m_now_camera_index];

		m_time_to_next_camera_change += _now_camera.m_time_between_camera_changes;

		APlayerController* _controller = UGameplayStatics::GetPlayerController(this, 0);

		if ((_controller->GetViewTarget() != _now_camera.m_camera) && (_now_camera.m_camera != nullptr)) {
			if (_now_camera.m_sommth_blend_time <= 0.0f) {
				_controller->SetViewTarget(_now_camera.m_camera);
			} else {
				_controller->SetViewTargetWithBlend(_now_camera.m_camera, _sommth_blend_time);
			}
			
		}
		m_now_camera_index++;
		if (m_now_camera_index >= m_camera_array.Num()) {
			m_now_camera_index = 0;
		}
		/*
		if ((_controller->GetViewTarget() != m_camera_1) && (m_camera_1 != nullptr)) {
			// SetViewTarget -> �ٷ� ī�޶� ��ȯ�ϴ� �Լ�
			_controller->SetViewTarget(m_camera_1);
		} else if ((_controller->GetViewTarget() != m_camera_2) && (m_camera_2 != nullptr)) {
			// SetViewTargetWithBlend-> �ε巴�� ī�޶� �̵���Ű�鼭 ��ȯ�ϴ� �Լ�
			_controller->SetViewTargetWithBlend(m_camera_2, _sommth_blend_time);
		}*/
	}
}

