// Fill out your copyright notice in the Description page of Project Settings.


#include "BlinkingActor.h"
#include "Engine.h"


// Sets default values
ABlinkingActor::ABlinkingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>("VisibleComponent");
	RootComponent = VisibleComponent;
	
	TimeAccumulator = 0.f;
	bIsBlinking = false;
	
}

// Called when the game starts or when spawned
void ABlinkingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlinkingActor::Blink()
{
	// Toggle bIsBlinking
	bIsBlinking = !bIsBlinking;
	UE_LOG(LogTemp, Warning, TEXT("BlinkingActor Blink function called, bIsBlinking: %s"), bIsBlinking ? TEXT("True") : TEXT("False"));

	
}

// Called every frame
void ABlinkingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Add rotation on Z-axis
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += DeltaTime *40.0f;
	SetActorRotation(NewRotation);

	// Check if bIsBlinking is true
	if(bIsBlinking)
	{
		TimeAccumulator += DeltaTime;
		if (TimeAccumulator >= 1.0f) // Every second
			{
			TimeAccumulator -= 1.0f;
			bool bIsVisible = VisibleComponent->IsVisible();
			VisibleComponent->SetVisibility(!bIsVisible); // Toggle visibility
			UE_LOG(LogTemp, Warning, TEXT("BlinkingActor is supposed to blink, new visibility: %s"), !bIsVisible ? TEXT("True") : TEXT("False"));
			}
	}
	
}


