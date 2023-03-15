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

	//CameraToFind = CreateDefaultSubobject<ACameraActor>(TEXT("Camera to find"));

	CustomCameraToFind = CreateDefaultSubobject<AMyCameraActor>(TEXT("Camera to find"));

	CameraBlendTime = 0.0f;
}

// Called when the game starts or when spawned
void ABlendTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(false);
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
			//Only works with one camera actor
			/*TArray<AActor*> FoundActors;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), CameraToFind, FoundActors);
			PlayerCharacterController->SetViewTargetWithBlend(FoundActors[0], CameraBlendTime, EViewTargetBlendFunction::VTBlend_Linear);*/

			//PlayerCharacterController->SetViewTargetWithBlend(CameraToFind, CameraBlendTime, EViewTargetBlendFunction::VTBlend_Linear);
			PlayerCharacterController->SetViewTargetWithBlend(CustomCameraToFind, CameraBlendTime, EViewTargetBlendFunction::VTBlend_Linear);
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

