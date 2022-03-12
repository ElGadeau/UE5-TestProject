// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "KnightAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UKnightAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	void SetIsWalking(bool value);
	void SetIsJumping(bool value);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		bool IsWalking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
		bool IsJumping;
};
