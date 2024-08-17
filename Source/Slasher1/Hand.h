// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Hand.generated.h"

/**
 * 
 */
class ACard;

UCLASS()
class SLASHER1_API UHand : public UObject
{
	GENERATED_BODY()
public:
    UHand();

	UFUNCTION(BlueprintCallable, Category = "Cards")
    void AddCard(ACard* Card);

    UFUNCTION(BlueprintCallable, Category = "Cards")
    void RemoveCard(ACard* Card);

    UFUNCTION(BlueprintCallable, Category = "Cards")
    TArray<ACard*> GetCards() const;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Cards")
    TArray<ACard*> CardsInHand;

};
