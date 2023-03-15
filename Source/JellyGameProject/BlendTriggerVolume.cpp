// Fill out your copyright notice in the Description page of Project Settings.


#include "BlendTriggerVolume.h"
#include "Components/BoxComponent.h"
#include "JellyGameProjectCharacter.h"
#include "Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ABlendTriggerVolume::ABlendTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CameraProxVolume"));
	OverlapVolume->SetupAttachment(RootComponent);

	CameraBlendTime = 0.0f;
}

// Called when the game starts or when spawned
void ABlendTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ABlendTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABlendTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (AJellyGameProjectCharacter* PlayerCheck = Cast<AJellyGameProjectCharacter>(OtherActor))
	{
		if (APlayerController* PlayerCharacterController = Cast<APlayerController>(PlayerCheck->GetController()))
		{
			TArray<AActor*> FoundActors;
			//UGameplayStatics::GetAllActorsOfClass(GetWorld(), CameraToFind, FoundActors);

			PlayerCharacterController->SetViewTargetWithBlend(FoundActors[0], CameraBlendTime, EViewTargetBlendFunction::VTBlend_Linear);
		};
	};
}

void ABlendTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (AJellyGameProjectCharacter* PlayerCheck = Cast<AJellyGameProjectCharacter>(OtherActor))
	{
		if (APlayerController* PlayerCharacterController = Cast<APlayerController>(PlayerCheck->GetController()))
		{
			PlayerCharacterController->SetViewTargetWithBlend(PlayerCharacterController->GetPawn(), CameraBlendTime, EViewTargetBlendFunction::VTBlend_Linear);
		}
	}
}

