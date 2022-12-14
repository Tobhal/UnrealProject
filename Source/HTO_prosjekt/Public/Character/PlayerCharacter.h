// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class HTO_PROSJEKT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void HoriMove(float val);
	void VertMove(float val);

	void HoriRot(float val);
	void VertRot(float val);

	UPROPERTY(EditAnywhere, Category = "Camera")
		UCameraComponent* cam;

};
