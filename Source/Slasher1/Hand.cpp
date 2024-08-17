// Fill out your copyright notice in the Description page of Project Settings.

#include "Hand.h"
#include "Card.h"

UHand::UHand()
{
    // Initialize the hand (empty at the start)
    CardsInHand = TArray<ACard*>();
}

void UHand::AddCard(ACard* Card)
{
    if (Card)
    {
        CardsInHand.Add(Card);
    }
}

void UHand::RemoveCard(ACard* Card)
{
    if (Card)
    {
        CardsInHand.Remove(Card);
    }
}

TArray<ACard*> UHand::GetCards() const
{
    return CardsInHand;
}
