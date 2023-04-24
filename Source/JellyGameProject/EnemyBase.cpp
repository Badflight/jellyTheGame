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
	StaticMeshComp->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyBase::Shoot()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy base function called"))
}

// Called to bind functionality to input


