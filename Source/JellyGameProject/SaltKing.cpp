// Fill out your copyright notice in the Description page of Project Settings.


#include "SaltKing.h"

// Sets default values
ASaltKing::ASaltKing()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponet = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component "));
	CapsuleComponet->InitCapsuleSize(42.0f,96.0f);
	RootComponent = CapsuleComponet;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	SkeletalMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASaltKing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASaltKing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//void ASaltKing::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}

