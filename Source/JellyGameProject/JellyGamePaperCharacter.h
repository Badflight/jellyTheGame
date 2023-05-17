// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "GameFramework/Character.h"
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"
#include "JellyGamePaperCharacter.generated.h"

/**
 * 
 */
UCLASS()
class JELLYGAMEPROJECT_API AJellyGamePaperCharacter : public APaperCharacter
{
	GENERATED_BODY()
public:
	AJellyGamePaperCharacter();

	
protected:
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
		void UpdateAnimation();
	//Setting the animation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		UPaperFlipbook* IdleAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		UPaperFlipbook* RunAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		UPaperFlipbook* JumpAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		UPaperFlipbook* AttackAnimation;
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowedPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowedPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Health;
	UFUNCTION(BlueprintCallable)
		void DamageRecived(float DamagePoint);
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
