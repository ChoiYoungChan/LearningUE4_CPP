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
	// TSubclassOf -> UE4에서 Uclass안정성을 보장하는 템플릿 클래스
		UFUNCTION(BlueprintCallable, Category = "UMG_Game")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG_Game")
		TSubclassOf<UUserWidget> StartingWidgetClass;

	UPROPERTY()
		UUserWidget* CurrentWidget;
};
