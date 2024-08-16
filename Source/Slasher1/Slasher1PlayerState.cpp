// Fill out your copyright notice in the Description page of Project Settings.

#include "Slasher1PlayerState.h"
#include "GameFramework/Actor.h"
#include "Card.h"  


ASlasher1PlayerState::ASlasher1PlayerState()
{
    // Initialize the player's score and position
    PlayerScore = 0;
    PlayerPosition = FVector::ZeroVector;  // Start at the origin (0, 0, 0)

    // Initialize the player's hand (empty at the start)
    SpecialCardHand = TArray<ACard*>();
}

void ASlasher1PlayerState::AddScore(int32 Points)
{
    PlayerScore += Points;
}



void ASlasher1PlayerState::SetPlayerPosition(FVector NewPosition)
{
    PlayerPosition = NewPosition;
}

FVector ASlasher1PlayerState::GetPlayerPosition() const
{
    return PlayerPosition;
}

void ASlasher1PlayerState::AddCardToHand(ACard* NewCard)
{
    if (NewCard)
    {
        SpecialCardHand.Add(NewCard);
    }
}

void ASlasher1PlayerState::RemoveCardFromHand(ACard* CardToRemove)
{
    if (CardToRemove)
    {
        SpecialCardHand.Remove(CardToRemove);
    }
}

const TArray<ACard*>& ASlasher1PlayerState::GetSpecialCardHand() const
{
    return SpecialCardHand;
}
