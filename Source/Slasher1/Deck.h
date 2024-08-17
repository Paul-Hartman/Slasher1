// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Deck.generated.h"


class ACard;
/**
 * 
 */
UCLASS()
class SLASHER1_API UDeck : public UObject
{
	GENERATED_BODY()

public:
    UDeck();

protected:
    // The cards in the deck
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cards")
    TArray<ACard*> CardsInDeck;

public:
    // Shuffles the deck
    UFUNCTION(BlueprintCallable, Category = "Deck")
    void ShuffleDeck();

    // Draws a card from the top of the deck
    UFUNCTION(BlueprintCallable, Category = "Deck")
    ACard* DrawCard();

    // Adds a card to the deck
    UFUNCTION(BlueprintCallable, Category = "Deck")
    void AddCardToDeck(ACard* Card);

    // Discards a card from the deck (optional, if you implement discard logic)
    UFUNCTION(BlueprintCallable, Category = "Deck")
    void DiscardCard(ACard* Card);
	
};
