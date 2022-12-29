// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_Main.h"
#include "DrawDebugHelpers.h"
void APC_Main::CallFormation()
{
	for (FVector& unitPosition : FormationVector)
	{
		DrawDebugCircle(GetWorld(), unitPosition, 10.f, 12, FColor::Black, false, 20.f);
	}
}

void APC_Main::MakeFormation(FVector rightClick, TArray<AActor*> units)
{
	if (rightClick == FVector(0.f))
	{
		FormationVector.AddUnique(units[0]->GetActorLocation());
		NewPosition = units[0]->GetActorLocation();
	}
	else
	{
		FormationVector.AddUnique(rightClick);
		NewPosition = rightClick;
	}
	switch (formationType)
	{
	case StraightLineVerticalRight:
		GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Black, "1");
		for (AActor* unit : units)
		{
			CreateFormationArray(LineRight());
			GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Black, "1");
		}
		break;
	case StraightLineVerticalLeft:
		ArrayInput = LineLeft();
		break;
	case StraightLineHorizontalUp:
		ArrayInput = LineUp();
		break;
	case StraightLineHorizontalDown:
		ArrayInput = LineDown();
		break;
	}
	
}

void APC_Main::CreateFormationArray(FVector input)
{
	FormationVector.AddUnique(input);
	NewPosition.Set(input.X, input.Y, input.Z);
}

FVector APC_Main::LineLeft()
{
	return FVector(NewPosition.X, NewPosition.Y - 150.f, NewPosition.Z);
}

FVector APC_Main::LineRight()
{
	return FVector(NewPosition.X, NewPosition.Y + 150.f, NewPosition.Z);
}

FVector APC_Main::LineUp()
{
	return FVector(NewPosition.X + 150, NewPosition.Y, NewPosition.Z);
}

FVector APC_Main::LineDown()
{
	return FVector(NewPosition.X - 150, NewPosition.Y, NewPosition.Z);
}


