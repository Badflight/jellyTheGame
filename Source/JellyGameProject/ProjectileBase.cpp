// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBase.h"

// Sets default values
AProjectileBase::AProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!SphereCollider) {
		SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
		SphereCollider->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
		SphereCollider->InitSphereRadius(40.0f);
		SphereCollider->OnComponentHit.AddDynamic(this, &AProjectileBase::OnHit);
		RootComponent = SphereCollider;
	}


	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);


	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->SetUpdatedComponent(SphereCollider);
	ProjectileMovement->InitialSpeed = 500.0f;
	ProjectileMovement->MaxSpeed = 500.0f;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	
	
}


// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	//FireInDirection(FVector(50, 50, 50));
}

// Called every frame
void AProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectileBase::FireInDirection(const FVector& Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("Fire in direction function called"));
	//ProjectileMovement->Velocity = Direction*1000;
}


void AProjectileBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && (OtherActor!=this) && OtherComp) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
		UE_LOG(LogTemp,Warning,TEXT("Hit"))
		Destroy();
	}
	UE_LOG(LogTemp,Warning, TEXT("Function called"))
}


