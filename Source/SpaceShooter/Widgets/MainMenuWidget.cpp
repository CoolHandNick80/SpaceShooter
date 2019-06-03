// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"


void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupData();

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Purple, "InitializeInputComponent");

	InputBinding = PlayerController->InputComponent->BindAxis("MoveForward", this, &UMainMenuWidget::ScrollButtons);
	InputBinding.bConsumeInput = false;
}

/*void UMainMenuWidget::InitializeInputComponent()
{
	Super::InitializeInputComponent();

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Purple,"InitializeInputComponent");

	InputBinding = InputComponent->BindAxis("MoveForward", this, &UMainMenuWidget::ScrollButtons);
	InputBinding.bConsumeInput = false;
}*/


void UMainMenuWidget::SetupData()
{
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	verify(PlayerController != nullptr);

	NewGameButton = Cast<UButton>(WidgetTree->FindWidget("BTN_NewGame"));
	verify(NewGameButton != nullptr);

	if (NewGameButton != nullptr)
	{
		NewGameButton->OnHovered.Broadcast();
		ButtonsArray.Add(NewGameButton);
	}

	ContinueButton = Cast<UButton>(WidgetTree->FindWidget("BTN_Continue"));

	if (ContinueButton != nullptr)
	{
		ButtonsArray.Add(ContinueButton);
	}

	LoadGameButton = Cast<UButton>(WidgetTree->FindWidget("BTN_LoadGame"));

	if (LoadGameButton != nullptr)
	{
		ButtonsArray.Add(LoadGameButton);
	}

	QuitButton = Cast<UButton>(WidgetTree->FindWidget("BTN_Quit"));

	if (QuitButton != nullptr)
	{
		ButtonsArray.Add(QuitButton);
	}

	LastArrayIndex  = (ButtonsArray.Num()-1);

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::FromInt(LastArrayIndex));
}

void UMainMenuWidget::ScrollButtons(float InValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::SanitizeFloat(InValue));

	if (!FMath::IsNearlyZero(InValue, 0.3F))
	{
		if (InValue > 0.7F)
		{
			if (CurrentButtonIndex > 0)
			{
				PreviousButtonIndex = CurrentButtonIndex;
				CurrentButtonIndex -= 1;
			}
		}

		if (InValue < -0.7F)
		{
			if (CurrentButtonIndex < LastArrayIndex)
			{
				PreviousButtonIndex = CurrentButtonIndex;
				CurrentButtonIndex += 1;
			}
		}
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, FString::FromInt(CurrentButtonIndex));

	if (CurrentButtonIndex != PreviousButtonIndex)
	{
		ButtonsArray[PreviousButtonIndex]->OnUnhovered.Broadcast();
		ButtonsArray[CurrentButtonIndex]->OnHovered.Broadcast();
	}

}

