// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/InputComponent.h "
#include "MainMenuWidget.generated.h"


class UMyButton;

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry & MyGeometry, float InDeltaTime) override;
	
protected:

	

	UPROPERTY()
		int32 LastArrayIndex = 0;

	

	UPROPERTY()
		TArray<UMyButton*> ButtonsArray;
	
	UPROPERTY()
		UMyButton* NewGameButton = nullptr;

	UPROPERTY()
		UMyButton* ContinueButton = nullptr;

	UPROPERTY()
		UMyButton* LoadGameButton = nullptr;

	UPROPERTY()
		UMyButton* QuitButton = nullptr;

		
 
protected:

	void SetupData();
};
