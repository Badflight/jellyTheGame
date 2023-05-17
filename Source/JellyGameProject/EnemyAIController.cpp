// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyBase.h"
#include "EnemyBase2DPaperCharacter.h"


AEnemyAIController::AEnemyAIController(const FObjectInitializer& objectInitializer)
{
	BlackBoardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
	BehaviorTreeComponet = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
}



void AEnemyAIController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);
	AEnemyBase* Char = Cast<AEnemyBase>(pawn);
	AEnemyBase2DPaperCharacter* Char2 = Cast<AEnemyBase2DPaperCharacter>(pawn);

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
	else if (Char2 != nullptr && Char2->TreeAsset != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Behavior tree found CHARACTER"));
		//Starts blackboard

		BlackBoardComponent->InitializeBlackboard(*Char2->TreeAsset->BlackboardAsset);

		//Set up the keys, for new keys add within .h file
		EnemyKeyID = BlackBoardComponent->GetKeyID("TargetActor");

		BehaviorTreeComponet->StartTree(*Char2->TreeAsset);

		bool isRunning = BehaviorTreeComponet->IsRunning();

		UE_LOG(LogTemp, Warning, TEXT("The behavior tree is: %s"), (isRunning ? TEXT("RUNNING") : TEXT("NOT RUNNING")));
	}
	
}


