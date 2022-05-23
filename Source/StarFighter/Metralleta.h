// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Metralleta.generated.h"

UCLASS()
class STARFIGHTER_API AMetralleta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMetralleta();

	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired; 
	FTimerHandle MemberTimerHandle; 
	/** Sphere collision component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MetralletaMesh;


	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float MoveSpeedMetralleta;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void FireMetralleta();
	void FireShotMetralleta(FVector FireDirectionEnemigo);

	void ShotTimerExpired();
};
