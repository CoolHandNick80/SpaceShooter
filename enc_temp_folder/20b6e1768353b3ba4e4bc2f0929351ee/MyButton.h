// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Styling/SlateTypes.h "
#include "MyButton.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API UMyButton : public UButton
{
	GENERATED_BODY()

		UMyButton(const FObjectInitializer& ObjectInitializer);

protected:

	

	void StartTimer();

	void CheckFocus();

	UPROPERTY()
		FTimerHandle ButtonTimerHandle;



};
