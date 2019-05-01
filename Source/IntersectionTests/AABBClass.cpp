// Fill out your copyright notice in the Description page of Project Settings.

#include "AABBClass.h"


// Sets default values
AAABBClass::AAABBClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAABBClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAABBClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AAABBClass::GetMin()
{
	return boxMin;
}

FVector AAABBClass::GetMax()
{
	return boxMax;
}

int FindMin(const int &a, const int &b)
{
	int min = a < b ? a : b;
	return min;
}

int FindMax(const int &a, const int &b)
{
	int max = a > b ? a : b;
	return max;
}

void AAABBClass::SetMinMax(FVector origin, FVector extent)
{

	float boxMinX = FindMin(origin.X - extent.X, origin.X + extent.X);
	float boxMaxX = FindMax(origin.X - extent.X, origin.X + extent.X);

	float boxMinY = FindMin(origin.Y - extent.Y, origin.Y + extent.Y);
	float boxMaxY = FindMax(origin.Y - extent.Y, origin.Y + extent.Y);

	float boxMinZ = FindMin(origin.Z - extent.Z, origin.Z + extent.Z);
	float boxMaxZ = FindMax(origin.Z - extent.Z, origin.Z + extent.Z);

	boxMin = FVector(boxMinX, boxMinY, boxMinZ);
	boxMax = FVector(boxMaxX, boxMaxY, boxMaxZ);
}