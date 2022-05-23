// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave.h"
#include "NaveAcuatica.generated.h"

/**
 *
 */
UCLASS()
class STARFIGHTER_API ANaveAcuatica : public ANave
{
	GENERATED_BODY()
private:

	//===================================================================================================================================================================
	ANaveAcuatica();
	
	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired; //tiempo que toma de la PC
	FTimerHandle MemberTimerHandle;//caracteristica que usaremos en el BeginPlay
	FTimerHandle MemberTimerHandle1;
public:
	
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;//Offset del spawn de la bala(para que no aparezca dentro de la nave)
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; //delay de spawn para el proyectil.
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float MoveSpeedAcuatica;

	float MovingAX;
	float MovingAY; 


	
public:

	virtual void BeginPlay() override;

	void Tick(float DeltaSeconds); 

	void FireAcuatica(); //Llamamos a FireShotAcuatica
	void FireShotAcuatica(FVector FireDirectionEnemigo);

	void ShotTimerExpired();

public:
	UFUNCTION()
		virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal,
		FVector NormalImpulse, const FHitResult& Hit)override;//Registro de golpe

	TMap<FString, int32>AcuaticaInfo;




	void CuentaBalas();
	void MuestraCuentaBalas();
};

