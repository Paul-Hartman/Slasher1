// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Hand.h"  // Include the header file for your UHand class
#include "Slasher1PlayerState.generated.h"

/**
 * 
 */
class ACard;
UCLASS()
class SLASHER1_API ASlasher1PlayerState : public APlayerState
{
	GENERATED_BODY()
	


public:
    ASlasher1PlayerState();

protected:
    // The player's current score
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
    int32 PlayerScore;

    // The player's current position in the game (e.g., grid or world position)
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player State")
    FVector PlayerPosition;

    // The player's hand of special cards
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cards")
    UHand* Hand;

public:
    // Functions to manage the player's score
    UFUNCTION(BlueprintCallable, Category = "Player State")
    void AddScore(int32 Points);

    // Functions to manage the player's position
    UFUNCTION(BlueprintCallable, Category = "Player State")
    void SetPlayerPosition(FVector NewPosition);

    UFUNCTION(BlueprintCallable, Category = "Player State")
    FVector GetPlayerPosition() const;

    // Functions to manage the player's hand of special cards
    UFUNCTION(BlueprintCallable, Category = "Cards")
    void AddCardToHand(class ACard* NewCard);

    UFUNCTION(BlueprintCallable, Category = "Cards")
    void RemoveCardFromHand(class ACard* CardToRemove);

    UFUNCTION(BlueprintCallable, Category = "Cards")
    UHand* GetHand() const;
};
