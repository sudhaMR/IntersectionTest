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

bool AIntersectionTestAlgorithm::DoesRayPlaneIntersect(APlaneClass* plane, FVector rayOrigin, FVector rayNormal, FVector rayEnd)
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

	float denominator = FVector::DotProduct(l, n);

	//Non-normalized dr to draw actual point of intersection
	float dr = FVector::DotProduct(rayNormal, plane->GetPlaneNormal());

	if (denominator > 1e-6)
	{
		float numerator = FVector::DotProduct(p0 - l0, n);

		//Non-normalized nr to draw actual point of intersection
		float nr =  FVector::DotProduct(plane->GetPlaneOrigin() - rayOrigin, plane->GetPlaneNormal());

		float t = numerator / denominator;

		//Get point of intersection in the scene
		FVector point = rayOrigin + (nr/dr) * rayNormal;

		if (denominator > 0)
		{

			GEngine->AddOnScreenDebugMessage(
				1, 0.1f, FColor::Green
				, FString::Printf(TEXT("Intersecting plane at = %f, %f, %f"), point.X, point.Y, point.Z), true, fontSize);

			PlaneIntersectionPoint = point;

			return true;

		}

	}
	

	//GEngine->AddOnScreenDebugMessage(
	//	1, 30.f, FColor::Red
	//	, TEXT("\nNo Intersection!"), true, fontSize);
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
	const FVector2D& fontSize = FVector2D(3.0f, 3.0f);

	float xt, xn;

	bool inside = true;

	if (rayOrigin.X < box->GetMin().X)
	{
		//Get delta between origin and box min at x
		xt = box->GetMin().X - rayOrigin.X;

		//If the delta is greater than end of ray, the ray ends before reaching the box, no intersection
		if (xt > rayEnd.X)
		{
			UE_LOG(LogTemp, Warning, TEXT("xt > xEnd"));
			return false;
		}

		// xt = (boxMin.x - rayOrigin.x)/rayEnd.x

		xt /= rayEnd.X;
		inside = false;
		xn = -1.0f;
	}
	else if (rayOrigin.X > box->GetMax().X)
	{
		xt = box->GetMax().X - rayOrigin.X;

		if (xt < rayEnd.X)
		{
			UE_LOG(LogTemp, Warning, TEXT("xt < xEnd"));
			return false;
		}

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
		{
			UE_LOG(LogTemp, Warning, TEXT("yt > yEnd"));
			return false;
		}

		yt /= rayEnd.Y;

		inside = false;
		yn = -1.0f;
	}
	else if (rayOrigin.Y > box->GetMax().Y)
	{
		yt = box->GetMax().Y - rayOrigin.Y;

		if (yt < rayEnd.Y)
		{
			UE_LOG(LogTemp, Warning, TEXT("yt < yEnd"));
			return false;
		}

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
		{
			UE_LOG(LogTemp, Warning, TEXT("zt > zEnd"));
			return false;
		}

		zt /= rayEnd.Z;

		inside = false;
		zn = -1.0f;
	}
	else if (rayOrigin.Z > box->GetMax().Z)
	{
		zt = box->GetMax().Z - rayOrigin.Z;

		if (zt < rayEnd.Z)
		{
			UE_LOG(LogTemp, Warning, TEXT("zt < zEnd"));
			return false;
		}

		zt /= rayEnd.Z;
		inside = false;
		zn = 1.0f;
	}
	else
	{
		zt = -1.0f;
	}

	int which = 0;
	float t = xt;
	if (yt > t)
	{
		which = 1;
		t = yt;
	}
	if (zt > t)
	{
		which = 2;
		t = zt;
	}

	switch (which)
	{
		case 0:
		{
			float y = rayOrigin.Y + rayEnd.Y * t;

			if (y < box->GetMin().Y || y > box->GetMax().Y)
				return false;

			float z = rayOrigin.Z + rayEnd.Z * t;

			if (z < box->GetMin().Z || z > box->GetMax().Z)
				return false;
		}

		break;

		case 1:
		{
			float x = rayOrigin.X + rayEnd.X * t;

			if (x < box->GetMin().X || x > box->GetMax().X)
				return false;

			float z = rayOrigin.Z + rayEnd.Z * t;

			if (z < box->GetMin().Z || z > box->GetMax().Z)
				return false;
		}

		break;

		case 3:
		{
			float x = rayOrigin.X + rayEnd.X * t;

			if (x < box->GetMin().X || x > box->GetMax().X)
				return false;

			float y = rayOrigin.Y + rayEnd.Y * t;

			if (y < box->GetMin().Y || y > box->GetMax().Y)
				return false;
		}

		break;

	}

	FVector pointOfIntersection = rayOrigin + t * (rayEnd);

	AABBIntersectionPoint = pointOfIntersection;

	GEngine->AddOnScreenDebugMessage(
		2, 0.1f, FColor::Green
		, FString::Printf(TEXT("Intersect AABB at : %f, %f, %f"), pointOfIntersection.X, pointOfIntersection.Y, pointOfIntersection.Z), true, fontSize);

	return true;
}



/*

	GEngine->AddOnScreenDebugMessage(
		1, 30.f, FColor::Green
		, FString::Printf(TEXT("ray origin x : %f"), rayOrigin.X), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		2, 30.f, FColor::Green
		, FString::Printf(TEXT("box min x : %f"), box->GetMin().X), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		3, 30.f, FColor::Green
		, FString::Printf(TEXT("ray origin y : %f"), rayOrigin.Y), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		4, 30.f, FColor::Green
		, FString::Printf(TEXT("box min y : %f"), box->GetMin().Y), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		5, 30.f, FColor::Green
		, FString::Printf(TEXT("ray origin z : %f"), rayOrigin.Z), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		6, 30.f, FColor::Green
		, FString::Printf(TEXT("box min z : %f"), box->GetMin().Z), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		7, 30.f, FColor::Green
		, FString::Printf(TEXT("ray end x : %f"), rayEnd.X), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		8, 30.f, FColor::Green
		, FString::Printf(TEXT("ray end y : %f"), rayEnd.Y), true, fontSize);

	GEngine->AddOnScreenDebugMessage(
		9, 30.f, FColor::Green
		, FString::Printf(TEXT("ray end z : %f"), rayEnd.Z), true, fontSize);

		*/