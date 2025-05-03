// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::CheckFireCondition()
{
	if (InFireRange())
	{
		Fire();
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

bool ATower::InFireRange()
{
	if (Tank)
	{
		if (Tank->GetIsAlive() == false) return false;

		FVector TankLocation = Tank->GetActorLocation();
		float Distance = FVector::Dist(GetActorLocation(), TankLocation);

		if (Distance <= FireRange) return true;
	}
	return false;
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}