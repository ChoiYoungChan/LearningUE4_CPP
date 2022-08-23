// Copyright Epic Games, Inc. All Rights Reserved.
// UE4�� �ѹ��� �������� ������ ǥ���ϰ�, ��ȣ�ۿ�ó���� ����, �Ѱ��� ������ �� �ִ�.
// ������ ���� �Ҹ��ų �ʿ�� ���µ� ����Ʈ�� ���Ź� ���۷����ϴ� ���� ���Ŵ� UE4�� �������÷��� �ý����� ó��

#include "LearningCppGameModeBase.h"
#include <Blueprint/UserWidget.h>

void ALearningCppGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(StartingWidgetClass);

}

void ALearningCppGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> _NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}

	if (_NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget(GetWorld(), _NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}