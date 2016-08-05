// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandsOfTheVoid.h"
#include "MainHero.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AMainHero::AMainHero()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = false; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
	CameraBoom->bUsePawnControlRotation = false;

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

// Called when the game starts or when spawned
void AMainHero::BeginPlay()
{
	Super::BeginPlay();
	
	PC = Cast<APlayerController>(GetController());

	PC->bShowMouseCursor = true;
}

// Called every frame
void AMainHero::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FRotator NewRotation;
	FVector2D ScreenPosPlayer;
	FVector MousePos;

	MousePos.Z = 0.0f;
	PC->GetMousePosition(MousePos.X, MousePos.Y);
	UGameplayStatics::ProjectWorldToScreen(PC, GetActorLocation(), ScreenPosPlayer);
	NewRotation = UKismetMathLibrary::FindLookAtRotation(FVector(ScreenPosPlayer.X, ScreenPosPlayer.Y, 0.0f), MousePos);
	
	NewRotation.Roll =  GetActorRotation().Roll;
	NewRotation.Pitch = GetActorRotation().Pitch;
	NewRotation.Yaw = NewRotation.Yaw + 90;

	NewRotation = UKismetMathLibrary::RInterpTo(GetActorRotation(), NewRotation, DeltaTime, 10);
	SetActorRotation(NewRotation);
	
}

// Called to bind functionality to input
void AMainHero::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

float AMainHero::GetDirection()
{
	FVector VelNorm = GetVelocity();
	VelNorm.Normalize();
	//UE_LOG(LogTemp, Warning, TEXT("X: %f - Y: %f - Z: %f"), VelNorm.X, VelNorm.Y, VelNorm.Z);
	FVector ForwardVec = GetActorForwardVector();
	FVector RightVec = GetActorRightVector();

	float start = -1 * Dot3(VelNorm, ForwardVec);
	float target = Dot3(VelNorm, RightVec);
	FRotator result = UKismetMathLibrary::FindLookAtRotation(FVector(start, 0.0f, 0.0f), FVector(0.0f, target, 0.0f));

	return result.Yaw;
}

