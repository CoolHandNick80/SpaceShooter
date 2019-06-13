// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Widgets/MyButton.h"
#include "Kismet/GameplayStatics.h"


void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupData();
	
	NewGameButton->SetKeyboardFocus();
}

void UMainMenuWidget::NativeTick(const FGeometry & MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	for (auto& Button : ButtonsArray)
	{
		Button->CheckFocus();
	}
}

void UMainMenuWidget::SetupData()
{
	NewGameButton = Cast<UMyButton>(WidgetTree->FindWidget("BTN_NewGame"));
	
	if (NewGameButton != nullptr)
	{
		ButtonsArray.Add(NewGameButton);
	}

	ContinueButton = Cast<UMyButton>(WidgetTree->FindWidget("BTN_Continue"));

	if (ContinueButton != nullptr)
	{
		ButtonsArray.Add(ContinueButton);
	}

	LoadGameButton = Cast<UMyButton>(WidgetTree->FindWidget("BTN_LoadGame"));

	if (LoadGameButton != nullptr)
	{
		ButtonsArray.Add(LoadGameButton);
	}

	QuitButton = Cast<UMyButton>(WidgetTree->FindWidget("BTN_Quit"));

	if (QuitButton != nullptr)
	{
		ButtonsArray.Add(QuitButton);
	}

	LastArrayIndex  = (ButtonsArray.Num()-1);
}



