// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(VisibleAnywhere)
	int32 VisibleAnywhereInt = 12;

	UPROPERTY(EditAnywhere)
	int32 EditAnywhereInt = 12;

	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 12;

	UPROPERTY(EditAnywhere)
	float Test = 32.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class UCapsuleComponent* CapsuleComp; // 전방 선언

	UPROPERTY()
	UStaticMeshComponent* BaseMesh; // Actor에 포함되기 때문에 전방 선언 필요 없음

	UPROPERTY()
	UStaticMeshComponent* TurretMesh; // Actor에 포함되기 때문에 전방 선언 필요 없음

	UPROPERTY()
	USceneComponent* ProjectileSpawnPoint; // 투사체 생성 포인트

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
