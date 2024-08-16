// Copyright Epic Games, Inc. All Rights Reserved.

#include "Slasher1GameMode.h"
#include "Slasher1PlayerController.h"
#include "Slasher1Character.h"
#include "UObject/ConstructorHelpers.h"


ASlasher1GameMode::ASlasher1GameMode()
	: bIsGameOver(false)
{
	// use our custom PlayerController class
	PlayerControllerClass = ASlasher1PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	// Initialize the game mode properties
	PrimaryActorTick.bCanEverTick = true; // Enable ticking

	// Set initial game phase
	CurrentGamePhase = EGamePhase::StartPhase;
}

void ASlasher1GameMode::BeginPlay()
{
	Super::BeginPlay();

	InitializeGame(); // Initialize the game setup

	SetGamePhase(EGamePhase::StartPhase); // Start the game in the StartPhase
}

void ASlasher1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle continuous game logic here, if needed
}

void ASlasher1GameMode::SetGamePhase(EGamePhase NewPhase)
{
	CurrentGamePhase = NewPhase;

	switch (CurrentGamePhase)
	{
	case EGamePhase::StartPhase:
		HandleStartPhase();
		break;

	case EGamePhase::PlayerTurnPhase:
		HandlePlayerTurnPhase();
		break;

	case EGamePhase::AITurnPhase:
		HandleAITurnPhase();
		break;

	case EGamePhase::ResolutionPhase:
		HandleResolutionPhase();
		break;

	case EGamePhase::EndPhase:
		HandleEndPhase();
		break;

	default:
		break;
	}
}

void ASlasher1GameMode::InitializeGame()
{
	// Initialize deck, AI, player controller, etc.
	// Example: Initialize the deck
	// Deck = NewObject<UDeck>(this);
	// Deck->InitializeDeckFromJson(TEXT("/Path/To/Your/DeckFile.json"));

	// Setup initial game state, deal initial cards, etc.
}

void ASlasher1GameMode::HandleStartPhase()
{
	// Logic for the start of the game
	// Shuffle deck, deal initial hands, etc.

	// Move to the next phase (Player's Turn)
	SetGamePhase(EGamePhase::PlayerTurnPhase);
}

void ASlasher1GameMode::HandlePlayerTurnPhase()
{
	// Logic for the player's turn
	// Wait for player input, allow them to play a card, etc.

	// After player's turn, transition to AI's turn
	SetGamePhase(EGamePhase::AITurnPhase);
}

void ASlasher1GameMode::HandleAITurnPhase()
{
	// Logic for the AI's turn
	// AI draws a card, makes decisions, etc.

	// After AI's turn, transition to resolution phase
	SetGamePhase(EGamePhase::ResolutionPhase);
}

void ASlasher1GameMode::HandleResolutionPhase()
{
	// Logic for resolving the outcome of the turn
	// Apply card effects, check win/loss conditions, etc.

	// After resolving, decide if the game should end or go back to the player's turn
	if (bIsGameOver)
	{
		SetGamePhase(EGamePhase::EndPhase);
	}
	else
	{
		SetGamePhase(EGamePhase::PlayerTurnPhase);
	}
}

void ASlasher1GameMode::HandleEndPhase()
{
	// Logic for the end of the game
	// Display results, restart the game, or exit

	// Optionally restart the game
	SetGamePhase(EGamePhase::StartPhase);
}
