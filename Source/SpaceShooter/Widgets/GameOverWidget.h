
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

class UMyGameInstance;

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

protected:

	

	UPROPERTY()
		UMyGameInstance* GameInstance = nullptr;

protected:

	void SetupData();

	UPROPERTY(BlueprintReadOnly)
		FName CurrentLevelName;

	
};
