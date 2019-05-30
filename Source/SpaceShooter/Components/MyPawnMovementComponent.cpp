// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawnMovementComponent.h"
#include "Pawns/MyPawn.h"

// Sets default values for this component's properties
UMyPawnMovementComponent::UMyPawnMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyPawnMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	SetupData();
}


// Called every frame
void UMyPawnMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	Move(HozSpeed, ForwardSpeed, VertSpeed);
}

void UMyPawnMovementComponent::SetupData()
{
	MyPawn = Cast<AMyPawn>(GetOwner());
	verify(MyPawn != nullptr);

	StaticMeshComponent = MyPawn->GetStaticMeshComponent();

	FRotator ActorRotation = StaticMeshComponent->GetComponentRotation();

	Roll = ActorRotation.Roll;
}

void UMyPawnMovementComponent::SetHorizontalSpeed(float Val)
{
	HozSpeed = SetSpeed(HozSpeed, Val);
}

void UMyPawnMovementComponent::SetForwardSpeed(float Val)
{
	ForwardSpeed = SetSpeed(ForwardSpeed, Val);
}

void UMyPawnMovementComponent::SetVerticalSpeed(float Val)
{
	VertSpeed = SetSpeed(VertSpeed, Val);
}

void UMyPawnMovementComponent::Move(float InHozSpeed, float InForwardSpeed, float InVerticalSpeed)
{
	MyPawn->SetActorLocation(MyPawn->GetActorLocation() + FVector::ForwardVector*InForwardSpeed, true);

	MyPawn->SetActorLocation(MyPawn->GetActorLocation() + FVector::RightVector*InHozSpeed, true);

	MyPawn->SetActorLocation(MyPawn->GetActorLocation() + FVector::UpVector*InVerticalSpeed, true);

	

	StaticMeshComponent->SetRelativeRotation(FMath::RInterpConstantTo(StaticMeshComponent->GetComponentRotation(), FRotator(StaticMeshComponent->GetComponentRotation().Pitch, StaticMeshComponent->GetComponentRotation().Yaw, (Roll + HozSpeed * 7)), GetWorld()->GetDeltaSeconds(), 80.F));
}

float UMyPawnMovementComponent::SetSpeed(float Speed, float Value)
{
	Speed = FMath::FInterpTo(Speed, (MovementSpeed*Value), GetWorld()->GetDeltaSeconds(), 6);

	return Speed;
}

