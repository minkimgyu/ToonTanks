// Fill out your copyright notice in the Description page of Project Settings.

#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTankPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (ToonTankPlayerController)
		{
			ToonTankPlayerController->SetPlayerEnabledState(false);
		}
		GameOver(false);
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor)) // ���� Ÿ�� Ŭ������ ĳ��Ʈ �ȴٸ�
	{
		DestroyedTower->HandleDestruction();
		TargetTowers--;

		if (TargetTowers == 0)
		{
			GameOver(true);
		}
	}
}

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

// �Լ� ��ü�� �����ϸ� �� ��
//void AToonTanksGameMode::StartGame()
//{
//
//}

int32 AToonTanksGameMode::GetTargetTowerCount()
{
	TArray<AActor*> Towers;
	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);

	return Towers.Num();
}

void AToonTanksGameMode::HandleGameStart()
{
	TargetTowers = GetTargetTowerCount();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	ToonTankPlayerController = Cast<AToonTankPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	if (ToonTankPlayerController)
	{
		ToonTankPlayerController->SetPlayerEnabledState(false);

		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
			ToonTankPlayerController,
			&AToonTankPlayerController::SetPlayerEnabledState,
			true
		);

		FTimerHandle PlayerEnableTimerHandler;

		GetWorldTimerManager().SetTimer(
			PlayerEnableTimerHandler, 
			PlayerEnableTimerDelegate, 
			StartDelay, 
			false
		); // ���� ����
	}
}
