// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenuWidget.h"
#include "GameModes/MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupData();
}

void UPauseMenuWidget::SetupData()
{
	GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));
	verify(GameMode != nullptr);
}
