// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "NewEnemyProjectile.generated.h"

UCLASS()
class JELLYGAMEPROJECT_API ANewEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewEnemyProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* CollisionComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* ProjectileMovementComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
		float DamageAmount;
};
