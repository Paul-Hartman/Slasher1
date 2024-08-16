// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

enum class EGamePhase : uint8
{
    StartPhase UMETA(DisplayName = "Start Phase"),
    PlayerTurnPhase UMETA(DisplayName = "Player Turn Phase"),
    AITurnPhase UMETA(DisplayName = "AI Turn Phase"),
    ResolutionPhase UMETA(DisplayName = "Resolution Phase"),
    EndPhase UMETA(DisplayName = "End Phase")
};
/**
 * 
 */
UCLASS()
class SLASHER1_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

	public:
    // Constructor
    AMyGameStateBase();

    // Current game phase
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State")
    EGamePhase CurrentGamePhase;

    // Current player score
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State")
    int32 PlayerScore;

    // Current round number
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game State")
    int32 CurrentRound;

    // Function to update the player score
    UFUNCTION(BlueprintCallable, Category = "Game State")
    void UpdatePlayerScore(int32 Points);

    // Function to set the current game phase
    UFUNCTION(BlueprintCallable, Category = "Game State")
    void SetGamePhase(EGamePhase NewPhase);

    // Function to advance to the next round
    UFUNCTION(BlueprintCallable, Category = "Game State")
    void AdvanceRound();
	
};
