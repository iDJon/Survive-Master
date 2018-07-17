// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Auto_Turret.generated.h"

UCLASS()
class SURVIVECONCEPT_API AAuto_Turret : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuto_Turret();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USphereComponent* AggroSphere;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
		void AggroResponse(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USceneComponent* MuzzlePoint;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class UStaticMeshComponent* Mesh2P;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Gameplay)
		void FireProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float FireInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float ShotSpread;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		class UClass* ProjectileClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class AActor* TargetActor;

	FTimerHandle FireTimer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
