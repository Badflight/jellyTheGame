// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyBase.h"


AEnemyAIController::AEnemyAIController(const FObjectInitializer& objectInitializer)
{
	BlackBoardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
	BehaviorTreeComponet = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
}



void AEnemyAIController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);
	//CHANGE SALT KING TO AN ENEMY BASE
	AEnemyBase* Char = Cast<AEnemyBase>(pawn);

	if (Char != nullptr && Char->TreeAsset != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Behavior tree found"));

		//Starts blackboard
		
		BlackBoardComponent->InitializeBlackboard(*Char->TreeAsset->BlackboardAsset);

		//Set up the keys, for new keys add within .h file
		EnemyKeyID = BlackBoardComponent->GetKeyID("TargetActor");

		BehaviorTreeComponet->StartTree(*Char->TreeAsset);

		bool isRunning = BehaviorTreeComponet->IsRunning();

		UE_LOG(LogTemp, Warning, TEXT("The behavior tree is: %s"), (isRunning ? TEXT("RUNNING") : TEXT("NOT RUNNING")));

	

		

	} 
	
}


