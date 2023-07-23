// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleGame/Public/GliderPawn.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AGliderPawn::AGliderPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	//FirstPersonCameraComponent->SetupAttachment(Root? Mesh?);
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AGliderPawn::BeginPlay()
{
	Super::BeginPlay();

	

	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
}

// Called every frame
void AGliderPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGliderPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AGliderPawn::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGliderPawn::Look);
	}

}



void AGliderPawn::Move(const FInputActionValue& Value)
{

	const FVector2D MovementVector = Value.Get<FVector2D>();

	GliderYaw = MovementVector.X;

	const FRotator NewRotation = FRotator(0.f, GliderYaw * YawSpeed, 0.0f);
	const FQuat QuatRotation = FQuat(NewRotation);
	

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	
}

void AGliderPawn::Look(const FInputActionValue& Value)
{

	
}
