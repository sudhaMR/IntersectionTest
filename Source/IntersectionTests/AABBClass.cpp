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

void AAABBClass::SetMin(FVector min)
{
	boxMin = min;
}

void AAABBClass::SetMax(FVector max)
{
	boxMax = max;
}