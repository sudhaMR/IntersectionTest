// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlaneClass.generated.h"

UCLASS()
class INTERSECTIONTESTS_API APlaneClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlaneClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	static APlaneClass* planeClassObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector planeOrigin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector planeExtent;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector planeNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector planeSurfaceNormal;

	UFUNCTION(BlueprintCallable)
		void SetPlaneOrigin(FVector origin);

	UFUNCTION(BlueprintCallable)
		void SetPlaneNormal(FVector normal);

	UFUNCTION(BlueprintCallable)
		FVector GetPlaneOrigin();

	UFUNCTION(BlueprintCallable)
		FVector GetPlaneNormal();
	
};
