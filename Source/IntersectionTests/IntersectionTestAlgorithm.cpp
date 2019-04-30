// Fill out your copyright notice in the Description page of Project Settings.

#include "IntersectionTestAlgorithm.h"
#include "PlaneClass.h"
#include "Engine.h"

// Sets default values
AIntersectionTestAlgorithm::AIntersectionTestAlgorithm()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AIntersectionTestAlgorithm::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AIntersectionTestAlgorithm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AIntersectionTestAlgorithm::DoesRayPlaneIntersect(APlaneClass* plane, FVector rayOrigin, FVector rayNormal)
{
	const FVector2D& fontSize = FVector2D(3.0f, 3.0f);

	//Plane normal (n)
	FVector n = plane->GetPlaneNormal().GetSafeNormal();

	//UE_LOG(LogTemp, Warning, TEXT("Plane normal: %f, %f, %f"), n.X, n.Y, n.Z);

	//Plane origin (p0)
	FVector p0 = plane->GetPlaneOrigin().GetSafeNormal();
	//Ray origin (l0)
	FVector l0 = rayOrigin.GetSafeNormal();
	//Ray direction(l)
	FVector l = rayNormal.GetSafeNormal();
	//UE_LOG(LogTemp, Warning, TEXT("Ray normal : %f, %f, %f"), l.X, l.Y, l.Z);
	
	float denominator = FVector::DotProduct(l, n);

	if (denominator > 1e-6)
	{
		float numerator = FVector::DotProduct(p0 - l0, n);
		float t = numerator / denominator;

		FVector point = p0 + t * l;

		UE_LOG(LogTemp, Warning, TEXT("dr : %f"), denominator);

		if(denominator > 0 )
			GEngine->AddOnScreenDebugMessage(
				1, 30.f, FColor::Green
				, FString::Printf(TEXT("Dr : %f"), denominator), true, fontSize);
	
		/*GEngine->AddOnScreenDebugMessage(
						1, 30.f, FColor::Green
						, FString::Printf(TEXT("Intersection at = %f, %f, %f"),point.X, point.Y, point.Z),true,fontSize);
			*/

		return (t >= 0);
	}
	

	GEngine->AddOnScreenDebugMessage(
		1, 30.f, FColor::Red
		, TEXT("\nNo Intersection!"), true, fontSize);
	return false;
}

bool AIntersectionTestAlgorithm::DoesLineLineIntersect(FVector aOrigin, FVector aEnd, FVector bOrigin, FVector bEnd)
{
	//Line equation d = ax + by + cz;

	//Line a

	return false;
}

bool AIntersectionTestAlgorithm::DoesRayAABBIntersect(FVector rayOrigin, FVector rayEnd, AAABBClass* box)
{
	float xt, xn;

	bool inside = true;

	if (rayOrigin.X < box->GetMin().X)
	{
		xt = box->GetMin().X - rayOrigin.X;

		if (xt > rayEnd.X)
			return false;

		xt /= rayEnd.X;
		inside = false;
		xn = -1.0f;
	}
	else if (rayOrigin.X > box->GetMax().X)
	{
		xt = box->GetMax().X - rayOrigin.X;

		if (xt < rayEnd.X)
			return false;

		xt /= rayEnd.X;
		inside = false;
		xn = 1.0f;
	}
	else
	{
		xt = -1.0f;
	}
	
	float yt, yn;
	if (rayOrigin.Y < box->GetMin().Y)
	{
		yt = box->GetMin().Y - rayOrigin.Y;

		if (yt > rayEnd.Y)
			return false;

		yt /= rayEnd.Y;

		inside = false;
		yn = -1.0f;
	}
	else if (rayOrigin.Y > box->GetMax().Y)
	{
		yt = box->GetMax().Y - rayOrigin.Y;

		if (yt < rayEnd.Y)
			return false;

		yt /= rayEnd.Y;
		inside = false;
		yn = 1.0f;
	}
	else
	{
		yt = -1.0f;
	}

	float zt, zn;
	if (rayOrigin.Z < box->GetMin().Z)
	{
		zt = box->GetMin().Z - rayOrigin.Z;

		if (zt > rayEnd.Z)
			return false;

		zt /= rayEnd.Z;

		inside = false;
		zn = -1.0f;
	}
	else if (rayOrigin.Z > box->GetMax().Z)
	{
		zt = box->GetMax().Z - rayOrigin.Z;

		if (zt < rayEnd.Z)
			return false;

		zt /= rayEnd.Z;
		inside = false;
		zn = 1.0f;
	}
	else
	{
		zt = -1.0f;
	}

	return true;
}