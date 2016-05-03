// Fill out your copyright notice in the Description page of Project Settings.

#include "Tejava.h"
#include "MouseHandler.h"
DECLARE_LOG_CATEGORY_EXTERN(MyLogCategory, Log, All);
DEFINE_LOG_CATEGORY(MyLogCategory)

// Sets default values
AMouseHandler::AMouseHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMouseHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMouseHandler::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
}

void AMouseHandler::Move_Sphere()
{
	if (Sphere)
	{
		Sphere->SetActorLocation(Sphere->GetActorLocation() + FVector(1, 1, 1) * 10.0f);
	}
}

void AMouseHandler::SetupPlayerInputComponent(class UInputComponent *InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Move_Sphere", IE_Pressed, this, &AMouseHandler::Move_Sphere);
}
