// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCameraActor.h"
#include "BlendTriggerVolume.generated.h"

UCLASS()
class JELLYGAMEPROJECT_API ABlendTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlendTriggerVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* OverlapVolume;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ACameraActor> CameraToFind;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class ACameraActor* CameraToFind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AMyCameraActor* CustomCameraToFind;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CameraBlendTime;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor);

	virtual void NotifyActorEndOverlap(AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
