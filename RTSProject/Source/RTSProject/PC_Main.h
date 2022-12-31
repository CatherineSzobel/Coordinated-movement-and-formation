// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Main.generated.h"
/**
 *
 */
UENUM(BlueprintType)
enum FormationType
{
	StraightLineVerticalRight,
	StraightLineVerticalLeft,
	StraightLineHorizontalUp,
	StraightLineHorizontalDown,
	Stairs,
	Square
};
UCLASS()
class RTSPROJECT_API APC_Main : public APlayerController
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Formation")
		void CallFormation();
	UFUNCTION(BlueprintCallable, Category = "Formation")
		void MakeFormation(FVector rightClick, TArray<AActor*> units);

	UPROPERTY(BlueprintReadWrite, Category = Position)
		TArray<FVector> FormationVector;

	//UPROPERTY(BlueprintReadWrite, Category = Unit)
	//	TArray<AActor*> Units;

	UPROPERTY(BlueprintReadWrite, Category = "Position")
		FVector NewPosition;

	UPROPERTY(BlueprintReadWrite, Category = "Position")
		TEnumAsByte<FormationType> formationType;

	UPROPERTY(BlueprintReadWrite, Category = "Units")
		int AmountOfUnits;

	UFUNCTION(BlueprintCallable, Category = "Formation")
		void CreateFormationArray(FVector input);
private:

	FVector ArrayInput;
	UFUNCTION(BlueprintCallable, BlueprintPure)
		FVector LineLeft();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		FVector LineRight();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		FVector LineUp();
	UFUNCTION(BlueprintCallable, BlueprintPure)
		FVector LineDown();
};
