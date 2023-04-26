// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "CustomPawnMovementSystem.h"
#include "Perception/PawnSensingComponent.h"
#include "EnemyBase.generated.h"

UCLASS()
class JELLYGAMEPROJECT_API AEnemyBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBehaviorTree* TreeAsset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCapsuleComponent* CapsuleComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCustomPawnMovementSystem* PawnMovementComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPawnSensingComponent* PawnSensorComp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void LeapAttack();
	
	
	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
