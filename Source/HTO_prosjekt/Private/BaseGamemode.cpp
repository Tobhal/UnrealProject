// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGamemode.h"
#include "Character/PlayerCharacter.h"

ABaseGamemode::ABaseGamemode()
{
    PrimaryActorTick.bCanEverTick = false;
    PrimaryActorTick.bStartWithTickEnabled = false;
    PrimaryActorTick.bAllowTickOnDedicatedServer = false;

    DefaultPawnClass = APlayerCharacter::StaticClass();
}
