// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/InputComponent.h "
#include "MainMenuWidget.generated.h"


class UButton;
class APlayerController;

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	//virtual void InitializeInputComponent() override;

	//virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

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
		TArray<UButton*> ButtonsArray;
	
	UPROPERTY()
		UButton* NewGameButton = nullptr;

	UPROPERTY()
		UButton* ContinueButton = nullptr;

	UPROPERTY()
		UButton* LoadGameButton = nullptr;

	UPROPERTY()
		UButton* QuitButton = nullptr;

	
		FInputBinding InputBinding = FInputBinding::FInputBinding();
 
public:

	float StickX = 0.F;
	
	float StickY = 0.F;

protected:

	void SetupData();

	UFUNCTION()
		void ScrollButtons(float InValue);


};
