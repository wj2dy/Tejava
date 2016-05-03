// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MouseHandler.generated.h"

UCLASS()
class TEJAVA_API AMouseHandler : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMouseHandler();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void Move_Sphere();

	virtual void SetupPlayerInputComponent(class UInputComponent *InputComponent) override;

	UPROPERTY(EditAnywhere)
		AActor *Sphere;
	
};
