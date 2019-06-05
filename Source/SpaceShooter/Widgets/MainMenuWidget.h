// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/InputComponent.h "
#include "MainMenuWidget.generated.h"


class UMyButton;
class APlayerController;

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;
	
protected:

	UPROPERTY()
		int32 PreviousButtonIndex = 0;

	UPROPERTY()
		int32 CurrentButtonIndex = 0;

	UPROPERTY()
		int32 LastArrayIndex = 0;

	UPROPERTY()
		APlayerController* PlayerController = nullptr;

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

		FInputBinding InputBinding = FInputBinding::FInputBinding();
 
protected:

	void SetupData();

	UFUNCTION()
		void ScrollButtons(float InValue);

	void CicleArray();

};
