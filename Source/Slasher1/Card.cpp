// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	   // Set default values for the card's properties
    Value = 0;
    bIsSpecial = false;
    FlavorText = "Default Flavor Text";

}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACard::GetValue() const
{
    return Value;
}

bool ACard::IsSpecial() const
{
    return bIsSpecial;
}

FString ACard::GetFlavorText() const
{
    return FlavorText;
}

void ACard::SetValue(int32 NewValue)
{
    Value = NewValue;
}

void ACard::SetIsSpecial(bool bNewIsSpecial)
{
    bIsSpecial = bNewIsSpecial;
}

void ACard::SetFlavorText(const FString& NewFlavorText)
{
    FlavorText = NewFlavorText;
}

