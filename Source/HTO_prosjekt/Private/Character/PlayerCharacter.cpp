// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	cam->K2_AttachTo(RootComponent);

	// Move the player camera
	cam->SetRelativeLocation(FVector(0, 0, 40));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal", this, &APlayerCharacter::HoriMove);
	InputComponent->BindAxis("Vertical", this, &APlayerCharacter::VertMove);

	InputComponent->BindAxis("HorizontalRot", this, &APlayerCharacter::HoriRot);
	InputComponent->BindAxis("VerticalRot", this, &APlayerCharacter::VertRot);
}

void APlayerCharacter::HoriMove(float val)
{
	if (val)
		AddMovementInput(GetActorRightVector(), val);
}

void APlayerCharacter::VertMove(float val)
{
	if (val)
		AddMovementInput(GetActorForwardVector(), val);
}

void APlayerCharacter::HoriRot(float val)
{
	if (val)
		AddActorLocalRotation(FRotator(0, val, 0));
}

void APlayerCharacter::VertRot(float val)
{
	if (val) {
		float temp = cam->GetRelativeRotation().Pitch + val;
		
		if (temp < 65 && temp > -65)
			cam->AddLocalRotation(FRotator(val, 0, 0));
	}
}