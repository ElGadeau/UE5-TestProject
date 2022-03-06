
#include "MyCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookVertical", this, &AMyCharacter::LookVertical);
	PlayerInputComponent->BindAxis("LookHorizontal", this, &AMyCharacter::LookHorizontal);
	PlayerInputComponent->BindAxis("CameraZoom", this, &AMyCharacter::ZoomCamera);
}

void AMyCharacter::MoveForward(const float Value)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector Direction = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);

	// const USceneComponent* Gimbals = Cast<USceneComponent>(GetDefaultSubobjectByName(TEXT("Gimbal")));
	// AddMovementInput(Gimbals->GetForwardVector(), Value);
}

void AMyCharacter::MoveRight(const float Value)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::LookVertical(float Value)
{
	if (InvertVerticalCamera)
	{
		AddControllerPitchInput(Value * -MouseAcceleration * GetWorld()->GetDeltaSeconds());
	}
	else
	{
		AddControllerPitchInput(Value * MouseAcceleration * GetWorld()->GetDeltaSeconds());
	}
}

void AMyCharacter::LookHorizontal(float Value)
{
	AddControllerYawInput(Value * MouseAcceleration * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::ZoomCamera(const float Value)
{
	CameraBoom->TargetArmLength += (-Value * 10.f);
}
