
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Slasher1GameMode.generated.h"

UENUM(BlueprintType)
enum class EGamePhase : uint8
{
    StartPhase UMETA(DisplayName = "Start Phase"),
    PlayerTurnPhase UMETA(DisplayName = "Player Turn Phase"),
    AITurnPhase UMETA(DisplayName = "AI Turn Phase"),
    ResolutionPhase UMETA(DisplayName = "Resolution Phase"),
    EndPhase UMETA(DisplayName = "End Phase")
};

UCLASS(minimalapi)
class ASlasher1GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
	ASlasher1GameMode();
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Function to transition to the next game phase
    UFUNCTION(BlueprintCallable, Category = "Game Mode")
    void SetGamePhase(EGamePhase NewPhase);

protected:
    // The current phase of the game
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game Mode")
    EGamePhase CurrentGamePhase;
    bool bIsGameOver;

    // Methods to handle each game phase
    void HandleStartPhase();
    void HandlePlayerTurnPhase();
    void HandleAITurnPhase();
    void HandleResolutionPhase();
    void HandleEndPhase();

    // Method to initialize the game elements (deck, AI, etc.)
    void InitializeGame();

};



