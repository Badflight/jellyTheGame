// Fill out your copyright notice in the Description page of Project Settings.

#include "JellyGamePaperCharacter.h"
#include "NewEnemyProjectile.h"

// Sets default values
ANewEnemyProjectile::ANewEnemyProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}*/
	if (!CollisionComponent) {
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("EnemyProjectilePre"));
		CollisionComponent->InitSphereRadius(15.0f);
		RootComponent = CollisionComponent;
	}
	if (!ProjectileMovementComp) {
		ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Comp"));
		ProjectileMovementComp->SetUpdatedComponent(CollisionComponent);
		ProjectileMovementComp->InitialSpeed = 300.0f;
		ProjectileMovementComp->MaxSpeed = 300.0f;
		ProjectileMovementComp->bRotationFollowsVelocity = true;
		ProjectileMovementComp->bShouldBounce = true;
		ProjectileMovementComp->ProjectileGravityScale = 0.0f;
	}
	if (!StaticMesh) {
		StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
		StaticMesh->SetupAttachment(RootComponent);
	}
	InitialLifeSpan = 3.0f;

	DamageAmount = 1.0f;
}

// Called when the game starts or when spawned
void ANewEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionComponent->OnComponentHit.AddDynamic(this, &ANewEnemyProjectile::OnHit);
	
	
}

// Called every frame
void ANewEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANewEnemyProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	/*if (OtherActor&&(OtherActor != this)) {
		AJellyGamePaperCharacter* playerRef = Cast<AJellyGamePaperCharacter>(OtherActor);
		if (playerRef) {
			playerRef->DamageRecived(DamageAmount);
		}
		Destroy();
	}
	UE_LOG(LogTemp, Warning, TEXT("Target hit"))
	Destroy();*/
}

