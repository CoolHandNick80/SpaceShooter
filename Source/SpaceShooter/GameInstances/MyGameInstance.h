// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Globals/GlobalTypes.h"
#include "MyGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreUpdated);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthUpdated);


/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()

		virtual void Init() override;

public:

	FOnScoreUpdated OnScoreUpdated;

	FOnHealthUpdated OnHealthUpdated;
protected:

	UPROPERTY()
		FPlayerData PlayerData;

public:

	FPlayerData* GetPlayerData() { return &PlayerData; }

	void UpdateScore(int32 InNewScore);
	
	void UpdateHealth(float InDamage);

	void SetupHealth();
};
