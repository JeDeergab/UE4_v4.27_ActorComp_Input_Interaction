// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Engine.h"


AMyPlayerController::AMyPlayerController()
{
	
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Let's say we added "BlinkingActorTag" to our BlinkingActor in Unreal Editor.
	BlinkingActor = nullptr;
	
	for (TActorIterator<AActor> It(GetWorld()); It; ++It)
	{
		if (It->ActorHasTag("BlinkingActorTag"))
		{
			BlinkingActor = Cast<ABlinkingActor>(*It);
			break;
		}
	}


	if (BlinkingActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("BlinkingActor found and assigned."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BlinkingActor NOT found or assigned."));
	}
}

void AMyPlayerController::Blink()
{
	if(BlinkingActor)
	{
		BlinkingActor->Blink();
	}

	UE_LOG(LogTemp, Warning, TEXT("Blink action triggered."));

	
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("Blink", IE_Pressed, this, &AMyPlayerController::Blink);
}

void AMyPlayerController::Tick(float DeltaTime)
{

	PrimaryActorTick.bCanEverTick = true;
	
}