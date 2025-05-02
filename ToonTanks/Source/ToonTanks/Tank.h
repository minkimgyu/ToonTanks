// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm; // 전방 선언

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera; // Actor에 포함되기 때문에 전방 선언 필요 없음

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* TankPlayerController;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction();
};
