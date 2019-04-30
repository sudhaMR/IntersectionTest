// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AABBClass.generated.h"

UCLASS()
class INTERSECTIONTESTS_API AAABBClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAABBClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		FVector GetMin();

	UFUNCTION(BlueprintCallable)
		FVector GetMax();

	UFUNCTION(BlueprintCallable)
		void SetMin(FVector min);

	UFUNCTION(BlueprintCallable)
		void SetMax(FVector max);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector boxOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector boxExtent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector boxMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector boxMax;
	
};
