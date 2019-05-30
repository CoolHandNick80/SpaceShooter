// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyPawnMovementComponent.generated.h"

class AMyPawn;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACESHOOTER_API UMyPawnMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyPawnMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

	AMyPawn* MyPawn = nullptr;

	UStaticMeshComponent* StaticMeshComponent = nullptr;

	float Roll = 0.F;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float DeltaSeconds = 0.F;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float HozSpeed = 0.F;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float VertSpeed = 0.F;

	UPROPERTY(EditDefaultsOnly)
		float ForwardSpeed = 0.F;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float MovementSpeed = 6.F;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float CurrentSpeed = 0.F;

protected:

	void SetupData();

public:

	void SetHorizontalSpeed(float Val);

	void SetForwardSpeed(float Val);

	void SetVerticalSpeed(float Val);

	void Move(float InHozSpeed, float InForwardSpeed, float InVerticalSpeed);

	float SetSpeed(float Speed, float Value);
		
};
