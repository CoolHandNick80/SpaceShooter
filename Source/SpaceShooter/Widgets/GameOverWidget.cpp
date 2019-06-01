// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameInstances/MyGameInstance.h"

void UGameOverWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	SetupData();
}

void UGameOverWidget::SetupData()
{
	GameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this));

	if (GameInstance != nullptr)
	{
		CurrentLevelName = GameInstance->GetCurrentLevel();
	}
	
}
