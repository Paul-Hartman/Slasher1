// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

// Sets default values


ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	   // Set default values for the card's properties
    Value = 0;
    bIsSpecial = false;
    FlavorText = "Default Flavor Text";
     UBoxComponent* CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
    CollisionComponent->SetCollisionProfileName(TEXT("Trigger"));
    CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ACard::OnOverlapBegin);

    RootComponent = CollisionComponent;

}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 ACard::GetValue() const
{
    return Value;
}

bool ACard::IsSpecial() const
{
    return bIsSpecial;
}

FString ACard::GetFlavorText() const
{
    return FlavorText;
}

void ACard::SetValue(int32 NewValue)
{
    Value = NewValue;
}

void ACard::SetIsSpecial(bool bNewIsSpecial)
{
    bIsSpecial = bNewIsSpecial;
}

void ACard::SetFlavorText(const FString& NewFlavorText)
{
    FlavorText = NewFlavorText;
}

void ACard::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
    if (OtherActor && (OtherActor != this) && OtherComp)
    {
        ASlasher1Character* Character = Cast<ASlasher1Character>(OtherActor);
        if (Character)
        {
            OnCardFlipped(Character);
        }
    }
}

void ACard::OnCardFlipped(ASlasher1Character* Character)
{
    if (bIsSpecial)
    {
        // Add this card to the player's hand if it is special
        if (Character && Character->GetPlayerState<ASlasher1PlayerState>())
        {
            UHand* PlayerHand = Character->GetPlayerState<ASlasher1PlayerState>()->GetHand();
            if (PlayerHand)
            {
                PlayerHand->AddCard(this);
            }
        }
    }
    
    // Optionally: Remove the card from the world or mark it as "flipped"
    Destroy();  // For example, remove the card actor after it's flipped
}

