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
		for (AActor* unit : units)
		{
			CreateFormationArray(LineRight());
		}
		break;
	case StraightLineVerticalLeft:
		for (AActor* unit : units)
		{
			CreateFormationArray(LineLeft());
		}
		break;
	case StraightLineHorizontalUp:
		for (AActor* unit : units)
		{
			CreateFormationArray(LineUp());
		}
		break;
	case StraightLineHorizontalDown:
		for (AActor* unit : units)
		{
			CreateFormationArray(LineDown());
		}
		break;
	case Stairs:
		for (int i = 0; i < units.Num(); i++)
		{
			if (((i + 1) % 2) == 0)
			{
				CreateFormationArray(LineUp());
			}
			else
			{
				CreateFormationArray(LineLeft());
			}
		}
		break;
	case Square:
		for (int i = 0; i < units.Num(); ++i)
		{
			if ((i + 1) == (units.Num() / 2))
			{
				CreateFormationArray(LineUp());
				ChangeToRight = true;
			}
			else
			{
				CreateFormationArray(LineLeft());
				if (ChangeToRight)
				{
					CreateFormationArray(LineRight());
				}
				else
				{
					CreateFormationArray(LineLeft());
				}
			}
		}
		break;
	case Circle:
		for (int i = 0; i < units.Num(); ++i)
		{
			
			CreateFormationArray(CreateCircle(i,units.Num()));
		}
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

FVector APC_Main::CreateCircle(int currentIdx, int totalIdx)
{
	float angle = currentIdx * (2.f * (PI / float(totalIdx)));
	float sinAngle = sin(angle) * CircleRadius;
	float cosAngle = cos(angle) * CircleRadius;
	return FVector(NewPosition.X + cosAngle, NewPosition.Y + sinAngle, NewPosition.Z );
}

