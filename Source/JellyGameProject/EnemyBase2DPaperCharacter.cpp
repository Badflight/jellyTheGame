// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase2DPaperCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/ConstructorHelpers.h"


AEnemyBase2DPaperCharacter::AEnemyBase2DPaperCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MaxWalkSpeed=500.0f;

	PawnSensorComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing Component"));
}

void AEnemyBase2DPaperCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyBase2DPaperCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyBase2DPaperCharacter::LeapAttack()
{
}
