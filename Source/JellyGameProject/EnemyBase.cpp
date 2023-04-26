// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsual collider"));
	RootComponent = CapsuleComponent;


	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh"));
	StaticMeshComp->SetupAttachment(CapsuleComponent);
	
	PawnMovementComp = CreateDefaultSubobject<UCustomPawnMovementSystem>(TEXT("Pawn Movement"));
	PawnMovementComp->UpdatedComponent;
	PawnMovementComp->MaxSpeed = 800.0f;

	PawnSensorComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensing Component"));
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	//LeapAttack();
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyBase::LeapAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy base function called"))
}

// Called to bind functionality to input


