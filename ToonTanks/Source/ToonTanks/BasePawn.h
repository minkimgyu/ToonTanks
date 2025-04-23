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


	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 12;

	UPROPERTY(EditAnywhere)
	float Test = 32.f;

	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultOnlyInt = 64;

	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnlyInt = 32;

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt = 32;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Test2 = 64.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Test3 = 32.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp; // 전방 선언

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh; // Actor에 포함되기 때문에 전방 선언 필요 없음

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh; // Actor에 포함되기 때문에 전방 선언 필요 없음

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint; // 투사체 생성 포인트

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Super Duper Variables", meta = (AllowPrivateAccess = "true"))
	//int32 VisibleAnywhereInt = 12;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Super Duper Variables", meta = (AllowPrivateAccess = "true"))
	//int32 EditAnywhereInt = 12;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
