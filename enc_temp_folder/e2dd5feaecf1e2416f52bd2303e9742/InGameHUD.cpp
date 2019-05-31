// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"

void AInGameHUD::SetupInGameGUI()
{
	if (InGameGUIClass != nullptr)
	{
		InGameGUI = CreateWidget<UUserWidget>(GetWorld(), InGameGUIClass);

		if (InGameGUI != nullptr)
		{
			InGameGUI->AddToViewport();
		}
	}
}

void AInGameHUD::SetupGameOverGUI()
{
	if (GameOverGUIClass != nullptr)
	{
		GameOverGUI = CreateWidget<UUserWidget>(GetWorld(), GameOverGUIClass);

		if (GameOverGUI != nullptr)
		{
			GameOverGUI->AddToViewport();
		}
	}
}
