// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuWidget.generated.h"

class AMyGameModeBase;

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
		
	virtual void NativeConstruct() override;

protected:

	UPROPERTY(BlueprintReadOnly)
		AMyGameModeBase* GameMode = nullptr;

protected:

	void SetupData();

	
};
