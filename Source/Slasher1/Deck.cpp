// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "Card.h"

UDeck::UDeck()
{
    // Initialize the deck (you can load cards here if needed)
    CardsInDeck = TArray<ACard*>();
}

void UDeck::ShuffleDeck()
{
    // Shuffle the deck using Unreal's Shuffle method
    for (int32 i = 0; i < CardsInDeck.Num(); i++)
    {
        int32 SwapIndex = FMath::RandRange(0, CardsInDeck.Num() - 1);
        CardsInDeck.Swap(i, SwapIndex);
    }
}

ACard* UDeck::DrawCard()
{
    if (CardsInDeck.Num() == 0)
    {
        return nullptr; // No more cards to draw
    }

    ACard* DrawnCard = CardsInDeck[0];
    CardsInDeck.RemoveAt(0);
    return DrawnCard;
}

void UDeck::AddCardToDeck(ACard* Card)
{
    if (Card)
    {
        CardsInDeck.Add(Card);
    }
}

void UDeck::DiscardCard(ACard* Card)
{
    if (Card)
    {
        CardsInDeck.Remove(Card);
        // Optionally, you can handle the card (e.g., move it to a discard pile)
    }
}

