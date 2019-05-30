// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/ShapeComponent.h"
#include "Engine/Engine.h"


void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));
	verify(GameMode != nullptr);

	StartTimer();
}

void AMyTriggerBox::SpawnFunction(UClass * InClass)
{
	if (InClass != nullptr)
	{
		const FVector& SpawnLocation = GetRandomLocation();

		FTransform SpawnTransform = FTransform(FRotator::FRotator(0.F, 180.F, 0.F), SpawnLocation, FVector::OneVector);

		GetWorld()->SpawnActor<AActor>(InClass, SpawnTransform);
	}
}

void AMyTriggerBox::SpawnFunction(UClass * InClass, float InDelay)
{
	FTimerHandle TimerHandle;

	FTimerDelegate Delegate;

	Delegate.BindUFunction(this, "SpawnFunction", InClass);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, Delegate, InDelay, false);
}

void AMyTriggerBox::StartTimer()
{
	GetWorld()->GetTimerManager().SetTimer(SpawnEnemiesTimerHandle, this, &AMyTriggerBox::UpdateTimer, 1.F, true);
}

void AMyTriggerBox::UpdateTimer()
{
	if(GameMode != nullptr)
	{
		if (GameMode->GetEnemyCount() < GameMode->GetMaxEnemies())
		{
			if (GameMode->GetEnemiesKilled() % 5 == 0 && GameMode->GetEnemiesKilled() != CurrentEnemiesKilled)
			{
				CurrentEnemiesKilled = GameMode->GetEnemiesKilled();

				SpawnFunction(EnemyTwoClass);

				GameMode->UpdateEnemyCount(1);
			}
			else
			{
				float Delay = FMath::RandRange(0.5F, 2.F);

				SpawnFunction(EnemyOneClass, Delay);

				GameMode->UpdateEnemyCount(1);
			}
		}
		else
		{
			//StopTimer();
		}


		int32 MaxAsteroidsNumber = FMath::RandRange(1, 3);

		for (int32 i = 0; i <= MaxAsteroidsNumber; i++)
		{
			float Delay = FMath::RandRange(0.5F, 3.F);

			SpawnFunction(AsteroidClass, Delay);
		}
	}
	
}

void AMyTriggerBox::StopTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(SpawnEnemiesTimerHandle);
}




FVector AMyTriggerBox::GetRandomLocation()
{
	FVector Origin; 
	FVector BoxExtent; 
	float SphereRadius = 0.F;
	
	const FVector BoxLocation = GetActorLocation();

	const UShapeComponent* CollisionComp = GetCollisionComponent();

	

	if (CollisionComp != nullptr)
	{
		FBoxSphereBounds Bounds = CollisionComp->CalcBounds(GetActorTransform());

		FVector RandomPoint = UKismetMathLibrary::RandomPointInBoundingBox(Bounds.Origin, Bounds.BoxExtent);

		return FVector(BoxLocation.X, RandomPoint.Y, RandomPoint.Z);

	}
	return BoxLocation;
}
