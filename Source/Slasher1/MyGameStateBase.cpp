// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameStateBase.h"


AMyGameStateBase::AMyGameStateBase()
{
    // Initialize default values
    CurrentGamePhase = EGamePhase::StartPhase;
    PlayerScore = 0;
    CurrentRound = 1;
}

void AMyGameStateBase::UpdatePlayerScore(int32 Points)
{
    PlayerScore += Points;
}

void AMyGameStateBase::SetGamePhase(EGamePhase NewPhase)
{
    CurrentGamePhase = NewPhase;
}

void AMyGameStateBase::AdvanceRound()
{
    CurrentRound++;
}
