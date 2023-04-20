// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class JELLYGAMEPROJECT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AEnemyAIController(const FObjectInitializer& objectInitializer);

	void OnPossess(APawn* const pawn) override;

	UPROPERTY(transient)
		class UBehaviorTreeComponent* BehaviorTreeComponet;

	UPROPERTY(transient)
		class UBlackboardComponent* BlackBoardComponent;

	

	uint8 EnemyKeyID;



};
