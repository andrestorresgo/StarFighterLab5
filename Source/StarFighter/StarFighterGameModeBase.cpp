// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveTerrestreEnemiga01.h"
#include "NaveAcuatica.h"
#include "InventoryActor.h"
void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();
		
		//Spawn de NaveAcuatica en el mapa con el SpawnNave en un timer
	
		GetWorldTimerManager().SetTimer(AcuaticaTimerHandle1, this, &AStarFighterGameModeBase::SpawnCapsulas, 02.0f, true, 1.0f);
	
	
		SpawnNave();

	

}

AStarFighterGameModeBase::AStarFighterGameModeBase()
{


}

void AStarFighterGameModeBase::SpawnNave()
{
	UE_LOG(LogTemp, Warning, TEXT("aparecio una Naveacuatica"));
	UWorld* const World = GetWorld();

	
	ejeX = rand() % 2000 + 1;
	ejeY = rand() % 2000 + 1;

	World->SpawnActor<ANaveAcuatica>(FVector(ejeX, ejeY, 112.0f), FRotator::ZeroRotator);//Spawn de NaveAcuatica en un punto aleatorio

}

void AStarFighterGameModeBase::SpawnCapsulas()
{


	UWorld* const World = GetWorld();


	PejeX = rand() %700 -500;


	World->SpawnActor<AInventoryActor>(FVector(900, PejeX, 112.0f), FRotator::ZeroRotator);
}

