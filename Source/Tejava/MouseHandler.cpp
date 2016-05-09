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
	bTargeting = false;
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

	if (bTargeting)
	{
		FVector vec;
		vec = Sphere->GetActorLocation();
		vec = TargetLocation - vec;
		vec.Z = 0;
		if (vec.Size() > SphereSpeed * DeltaTime)
		{
			vec /= vec.Size();
			vec *= SphereSpeed * DeltaTime;
			Sphere->SetActorLocation(Sphere->GetActorLocation() + vec);
		}
		else
		{
			Sphere->SetActorLocation(TargetLocation + FVector(0, 0, Sphere->GetActorLocation().Z));
			bTargeting = false;
		}
	}
}

void AMouseHandler::Move_Sphere()
{
	if (Sphere)
	{
		APlayerController *PlayerController = Cast<APlayerController>(GetController());
		if (PlayerController)
		{
			float LocationX, LocationY;
			PlayerController->GetMousePosition(LocationX, LocationY);
		//	UE_LOG(MyLogCategory, Log, TEXT("(%f, %f)"), LocationX, LocationY);
			FHitResult HitResult;
			AActor *Clicked;
			FCollisionQueryParams CollisionParams(false);
			CollisionParams.AddIgnoredActor(Sphere);
			if (PlayerController->GetHitResultAtScreenPosition(FVector2D(LocationX, LocationY),
				ECC_Visibility, CollisionParams, HitResult))
			{
				Clicked = HitResult.GetActor();
				if (Clicked == Floor)
				{
					TargetLocation = HitResult.Location;
					TargetLocation.Z = 0;
					bTargeting = true;
				}
			}
		}
	}
}

void AMouseHandler::SetupPlayerInputComponent(class UInputComponent *InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Move_Sphere", IE_Pressed, this, &AMouseHandler::Move_Sphere);
}
