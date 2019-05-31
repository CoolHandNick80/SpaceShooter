// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameInstances/MyGameInstance.h"
#include "Engine/engine.h"

void AMyGameModeBase::StartPlay()
{
	Super::StartPlay();

	SpawnGameplayCamera();

	SpawnInGameGUI();

	SetInputModeGameOnly();

	SetupHealth();
}

void AMyGameModeBase::SpawnGameplayCamera()
{
	APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	if (MyPawn != nullptr)
	{
		const FVector& PawnLocation = MyPawn->GetActorLocation();

		GameplayCamera = GetWorld()->SpawnActor<AMyGameplayCamera>(GameplayCameraClass, PawnLocation + (FVector::ForwardVector * 60), FRotator::ZeroRotator);

		if (GameplayCamera != nullptr)
		{
			GameplayCamera->SetTargetActor(MyPawn);

			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

			if (PlayerController != nullptr)
			{
				PlayerController->SetViewTarget(GameplayCamera);
			}
		}
	}
}

void AMyGameModeBase::SpawnInGameGUI()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (PlayerController != nullptr)
	{
		InGameHUD = Cast<AInGameHUD>(PlayerController->GetHUD());

		if (InGameHUD != nullptr)
		{
			InGameHUD->SetupInGameGUI();
		}
	}
}

void AMyGameModeBase::SetInputModeGameOnly()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (PlayerController != nullptr)
	{
		PlayerController->SetInputMode(FInputModeGameOnly());
	}
}

void AMyGameModeBase::SetInputModeUIOnly()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (PlayerController != nullptr)
	{
		PlayerController->SetInputMode(FInputModeUIOnly());
	}
}

void AMyGameModeBase::SetupHealth()
{
	GameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this));

	if (GameInstance != nullptr)
	{
		GameInstance->SetupHealth();
		GameInstance->UpdateHealth(0);
	}
}

void AMyGameModeBase::SetupData()
{
}

void AMyGameModeBase::PlayCamShake(TSubclassOf<class UCameraShake> InShake, FVector InEpicenter)
{
	UGameplayStatics::PlayWorldCameraShake(this, InShake, InEpicenter, NULL, NULL);
}

void AMyGameModeBase::UpdateEnemyCount(int32 InVal)
{
	EnemyCount += InVal;
}

void AMyGameModeBase::EnemyKilled()
{
	EnemiesKilled++;
	UpdateEnemyCount(-1);

	GameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(this));

	if (GameInstance != nullptr)
	{
		GameInstance->UpdateScore(EnemyScoreValue);
	}
}

void AMyGameModeBase::GameOver()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (PlayerController != nullptr)
	{
		InGameHUD = Cast<AInGameHUD>(PlayerController->GetHUD());

		if (InGameHUD != nullptr)
		{
			InGameHUD->SetupGameOverGUI();
			PlayerController->bShowMouseCursor = true;
			SetInputModeUIOnly();

		}
	}
}