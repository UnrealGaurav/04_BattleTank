// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player tank."));
	}
	else
	{
		// * for converting the returned string to TCHAR *.
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player.

		// Aim towards the player.
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready.
	}
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}