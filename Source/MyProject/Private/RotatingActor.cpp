// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;

}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	//Add rotation on Z-axis
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += DeltaTime *40.0f;
	SetActorRotation(NewRotation);
	*/

	/*
	//Scale the mesh
	FVector NewScale = MeshComponent->GetComponentScale();
	NewScale += FVector(DeltaTime);
	MeshComponent->SetWorldScale3D(NewScale);
	*/

	/*
	// Change the mesh color
	float Time = GetWorld()->GetTimeSeconds();
	FLinearColor Color(128.f, 0.f,128.f, 0.f);
	UMaterialInstanceDynamic* Material = MeshComponent->CreateDynamicMaterialInstance(0);
	if (Material != nullptr)
	{
		Material->SetVectorParameterValue(FName("Color"), Color);
	}
	*/
}

