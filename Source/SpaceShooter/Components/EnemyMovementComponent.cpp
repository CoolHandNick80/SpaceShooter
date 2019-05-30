// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyMovementComponent.h"
#include "GameModes/MyGameModeBase.h"
#include "Enemies/EnemyBase.h"
#include "Kismet/KismetMathLibrary.h"



// Sets default values for this component's properties
UEnemyMovementComponent::UEnemyMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	SetupData();
}


// Called every frame
void UEnemyMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	EnemyMovement(DeltaTime);
}

//Set variables
void UEnemyMovementComponent::SetupData()
{
	bMoveDirection = UKismetMathLibrary::RandomBool();

	MovementSpeed = FMath::FRandRange(MinSpeed, MaxSpeed);

	MyEnemy = Cast<AEnemyBase>(GetOwner());
	verify(MyEnemy != nullptr);
}

void UEnemyMovementComponent::EnemyMovement(float DeltaSeconds)
{
	if (MyEnemy != nullptr)
	{
		if (MyEnemy->bMoveEnabled == true)
		{
			FVector NewLocation = MyEnemy->GetActorLocation() + FVector::RightVector*(MovementSpeed * UKismetMathLibrary::SelectFloat(1, -1, bMoveDirection))*DeltaSeconds;
			MyEnemy->SetActorLocation(NewLocation, true);
		}
	}
}