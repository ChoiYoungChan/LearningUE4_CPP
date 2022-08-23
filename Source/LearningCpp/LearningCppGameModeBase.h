// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LearningCppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGCPP_API ALearningCppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public :
	// TSubclassOf -> UE4���� Uclass�������� �����ϴ� ���ø� Ŭ����
		UFUNCTION(BlueprintCallable, Category = "UMG_Game")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;
};
