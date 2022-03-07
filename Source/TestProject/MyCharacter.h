// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class TESTPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void LookVertical(float Value);
	void LookHorizontal(float Value);
	void ZoomCamera(float Value);

	UPROPERTY(EditAnywhere, Category = "Asset")
		float MouseAcceleration;

	UPROPERTY(EditAnywhere, Category = "Asset")
		bool InvertVerticalCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* Camera;

private:
	bool IsMovingFront;
	bool IsMovingRight;
};
