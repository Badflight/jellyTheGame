// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

#include "EnemyBase2DPaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class JELLYGAMEPROJECT_API AEnemyBase2DPaperCharacter : public APaperCharacter
{
	GENERATED_BODY()
public:
	AEnemyBase2DPaperCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBehaviorTree* TreeAsset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPawnSensingComponent* PawnSensorComp;
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void LeapAttack();
};
