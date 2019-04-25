// Fill out your copyright notice in the Description page of Project Settings.

#include "PlaneClass.h"
#include "DrawDebugHelpers.h"

// Sets default values
APlaneClass::APlaneClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//planeClassObject = this;
	planeOrigin = FVector(0.0f, 0.0f, 0.0f);
	planeNormal = FVector(0.0f, 0.0f, 0.0f);
}

// Called when the game starts or when spawned
void APlaneClass::BeginPlay()
{
	Super::BeginPlay();
	const FPlane plane(GetActorLocation(), FVector(0, 0, 500));
	planeOrigin = FVector(0, 0, 0);
	planeExtent = FVector(500, 500, 500);
}

// Called every frame
void APlaneClass::Tick(float DeltaTime)
{
	/*FVector const& planePos = GetActorLocation();
	FVector const& planeExtent = FVector(500.0f, 500.0f, 500.0f);
	FColor const& color = FColor::Red;
	FPlane const wallPlane(FVector(0.0f, 0.0f, 0.0f), FVector(0, 0, 500));

	FPlane const& p = wallPlane;*/
	Super::Tick(DeltaTime);
}

void APlaneClass::SetPlaneOrigin(FVector origin)
{
	planeOrigin = origin;
}

void APlaneClass::SetPlaneNormal(FVector normal)
{
	planeNormal = normal;
}

FVector APlaneClass::GetPlaneOrigin()
{
	return planeOrigin;
}


FVector APlaneClass::GetPlaneNormal()
{
	return planeNormal;
}