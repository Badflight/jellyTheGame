// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/CapsuleComponent.h"
#include "SaltKing.generated.h"

UCLASS()
class JELLYGAMEPROJECT_API ASaltKing : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASaltKing();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCapsuleComponent* CapsuleComponet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBehaviorTree* TreeAsset;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
