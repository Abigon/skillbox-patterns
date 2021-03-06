// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkillboxPatternsCharacter.h"
#include "SkillboxPatternsGameMode.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraShake.h"
#include "Kismet/GameplayStatics.h"
#include "Singleton/SingletonConnector.h"
#include "State/NewTestActor.h"
#include "Command/LoadGameCommand.h"
#include "Command/SaveGameCommand.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// ASkillboxPatternsCharacter

ASkillboxPatternsCharacter::ASkillboxPatternsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASkillboxPatternsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASkillboxPatternsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASkillboxPatternsCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASkillboxPatternsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASkillboxPatternsCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASkillboxPatternsCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASkillboxPatternsCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ASkillboxPatternsCharacter::OnResetVR);


	// ??????? ?????? ? ???????? ?????????? ? ????????
	// L - ????????, O - ??????????
	PlayerInputComponent->BindAction("LoadGame", IE_Released, this, &ASkillboxPatternsCharacter::CallLoadGame);
	PlayerInputComponent->BindAction("SaveGame", IE_Released, this, &ASkillboxPatternsCharacter::CallSaveGame);

}


void ASkillboxPatternsCharacter::OnResetVR()
{
	// If SkillboxPatterns is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in SkillboxPatterns.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ASkillboxPatternsCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ASkillboxPatternsCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ASkillboxPatternsCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASkillboxPatternsCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASkillboxPatternsCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASkillboxPatternsCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ASkillboxPatternsCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Singleplay
	auto Connector = USingletonConnector::Get("Character");

	// ????????????? ?? ??????? ?? ???? ???? ?? ?????
	TArray<AActor*> ListOfSpheres;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANewTestActor::StaticClass(), ListOfSpheres);

	for (auto Sphere : ListOfSpheres)
	{
		auto TestSphere = Cast<ANewTestActor>(Sphere);
		if (TestSphere)
		{
			TestSphere->OnChangeState.AddUObject(this, &ASkillboxPatternsCharacter::PlayCameraShake);
		}
	}

	// ????????? ??????? ?????????? ? ????????
	auto MyGameMode = Cast<ASkillboxPatternsGameMode>(UGameplayStatics::GetGameMode(this));

	auto SGC = NewObject<USaveGameCommand>();
	SGC->SetReceiver(MyGameMode);
	SaveGameCommand = SGC;

	auto LGC = NewObject<ULoadGameCommand>();
	LGC->SetReceiver(MyGameMode);
	LoadGameCommand = LGC;
}

void ASkillboxPatternsCharacter::PlayCameraShake()
{
	const auto MyController = GetController<APlayerController>();
	if (!MyController || !MyController->PlayerCameraManager) return;

	MyController->PlayerCameraManager->StartCameraShake(CameraShake);
}

void ASkillboxPatternsCharacter::CallSaveGame()
{
	if (SaveGameCommand)
	{
		SaveGameCommand->Execute();
	}
}

void ASkillboxPatternsCharacter::CallLoadGame()
{
	if (LoadGameCommand)
	{
		LoadGameCommand->Execute();
	}
}