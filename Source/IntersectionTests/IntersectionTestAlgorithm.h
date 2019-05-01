// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "PlaneClass.h"
#include "AABBClass.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IntersectionTestAlgorithm.generated.h"

UCLASS()
class INTERSECTIONTESTS_API AIntersectionTestAlgorithm : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AIntersectionTestAlgorithm();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class APlaneClass> planeObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool DoesRayPlaneIntersect(APlaneClass* plane, FVector rayOrigin, FVector rayNormal, FVector rayEnd);

	UFUNCTION(BlueprintCallable)
	bool DoesLineLineIntersect(FVector aOrigin, FVector aEnd, FVector bOrigin, FVector bEnd);

	UFUNCTION(BlueprintCallable)
	bool DoesRayAABBIntersect(FVector rayOrigin, FVector rayEnd, AAABBClass* box);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector AABBIntersectionPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector PlaneIntersectionPoint;

};