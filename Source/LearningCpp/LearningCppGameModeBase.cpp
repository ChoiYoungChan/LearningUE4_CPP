// Copyright Epic Games, Inc. All Rights Reserved.
// UE4는 한번에 여러개의 위젯을 표시하고, 상호작용처리가 가능, 한개씩 제거할 수 있다.
// 위젯을 직접 소멸시킬 필요는 없는데 뷰포트의 제거및 레퍼런싱하는 변수 제거는 UE4의 가비지컬렛견 시스템이 처리

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