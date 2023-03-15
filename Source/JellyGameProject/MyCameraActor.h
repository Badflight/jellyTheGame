// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "MyCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class JELLYGAMEPROJECT_API AMyCameraActor : public ACameraActor
{
	GENERATED_BODY()
public:
	UFUNCTION()
		void FindPlayerLocation();
};
