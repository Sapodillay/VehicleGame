// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"

//Input includes
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "GliderPawn.generated.h"

UCLASS()
class VEHICLEGAME_API AGliderPawn : public APawn
{
	GENERATED_BODY()


	//Movement of the camera is seperate to the main pawn.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true))
	UCameraComponent* FirstPersonCameraComponent;


#pragma region Input

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* MovementAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* LookAction;

#pragma endregion Input

	UPROPERTY(VisibleAnywhere, Category = Movement)
	float GliderYaw;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float YawSpeed;

	//Temporarily is const, will be changed at runtime inside Move.
	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float MovementSpeed;

	void HandleGliderPhysics();

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	

public:
	// Sets default values for this pawn's properties
	AGliderPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
