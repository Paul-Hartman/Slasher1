// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Slasher1Character.h"  // Include only if you need to directly interact with ASlasher1Character
#include "Components/BoxComponent.h"
#include "Slasher1PlayerState.h"
#include "Hand.h"
#include "Card.generated.h"




//class Slasher1Character;

UCLASS()
class SLASHER1_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

		// Called every frame
	virtual void Tick(float DeltaTime) override;

	    // Getters for the card properties
    UFUNCTION(BlueprintCallable, Category = "Card")
    int32 GetValue() const;

    UFUNCTION(BlueprintCallable, Category = "Card")
    bool IsSpecial() const;

    UFUNCTION(BlueprintCallable, Category = "Card")
    FString GetFlavorText() const;

    // Setters for the card properties
    UFUNCTION(BlueprintCallable, Category = "Card")
    void SetValue(int32 NewValue);

    UFUNCTION(BlueprintCallable, Category = "Card")
    void SetIsSpecial(bool bNewIsSpecial);

    UFUNCTION(BlueprintCallable, Category = "Card")
    void SetFlavorText(const FString& NewFlavorText);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	   // Card value, affects gameplay
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    int32 Value;

    // Whether the card has a special effect
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    bool bIsSpecial;

    // Flavor text for the card
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card")
    FString FlavorText;

   UFUNCTION(BlueprintCallable, Category = "Card")
   void OnCardFlipped(ASlasher1Character* Character);

   UFUNCTION()
   void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);



};
