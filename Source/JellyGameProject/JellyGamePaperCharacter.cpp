// Fill out your copyright notice in the Description page of Project Settings.


#include "JellyGamePaperCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/SpringArmComponent.h"

AJellyGamePaperCharacter::AJellyGamePaperCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	GetCharacterMovement()->JumpZVelocity = 900.0f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = false;

	CameraBoom->bEnableCameraLag = true;
	CameraBoom->bEnableCameraRotationLag = false;
	CameraBoom->CameraLagSpeed = 6.0f;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCapsuleComponent()->SetCapsuleSize(70.0f, 80.0f);
	Health = 10;
}

void AJellyGamePaperCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AJellyGamePaperCharacter::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void AJellyGamePaperCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateAnimation();
}

void AJellyGamePaperCharacter::DamageRecived(float DamagePoint)
{
	UE_LOG(LogTemp, Warning, TEXT("Damage function called"));
	UE_LOG(LogTemp, Warning, TEXT("Damage amount: %f"), DamagePoint);
}

void AJellyGamePaperCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
		if (Value > 0.0f) {
			const FQuat newRotation(0, 0, 0, 0);
			SetActorRelativeRotation(newRotation);
			//GetSprite()->SetRelativeRotation(newRotation);
		}
		else if (Value < 0.0f) {
			const FQuat newRotation(0, 0, 270, 0);
			SetActorRelativeRotation(newRotation);
			
			//GetSprite()->SetRelativeRotation(newRotation);
			//control rotation has been set to false and camera boon rotation has been set to true
		}
	}
}

void AJellyGamePaperCharacter::UpdateAnimation()
{
	FVector playerSpeed = GetCharacterMovement()->GetCurrentAcceleration();
	FVector playerVelocity = GetCharacterMovement()->Velocity;
	float playerZ = playerVelocity.Z;
	bool isFalling = GetCharacterMovement()->IsFalling();
	float speed = playerSpeed.Length();
	//will change the flip book to the run animation if the speed changes
	if (speed > 3.0f) {
		GetSprite()->SetFlipbook(RunAnimation);
	}
	else if (speed < 3.0f) {
		GetSprite()->SetFlipbook(IdleAnimation);
	}
	if (isFalling) {
		GetSprite()->SetFlipbook(JumpAnimation);
	}
}


