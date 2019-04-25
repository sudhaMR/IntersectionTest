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

	//DoesRayPlaneIntersect(APlaneClass::planeClassObject->planeOrigin, APlaneClass::planeClassObject->planeNormal, 
}

bool AIntersectionTestAlgorithm::DoesRayPlaneIntersect(APlaneClass* plane, FVector rayOrigin, FVector rayNormal)
{
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

		UE_LOG(LogTemp, Warning, TEXT("t : %f"), t);
		GEngine->AddOnScreenDebugMessage(
						1, 30.f, FColor::Green
						, FString::Printf(TEXT("Intersection: t = %f"),t));
			
		return (t >= 0);
	}
	

	GEngine->AddOnScreenDebugMessage(
		1, 30.f, FColor::Red
		, TEXT("\nNo Intersection!"));
	return false;
}

//bool AIntersectionTestAlgorithm::DoesRayPlaneIntersect(APlaneClass* plane, AIntersectionTestsPawn* pawn, FVector SurfaceNormal)
//{
//	bool Result = false;
//
//	float PlaneD = 0.0f;
//
//	FVector RayOrigin = pawn->GetPawnOrigin();
//	FVector RayDelta = (RayOrigin + pawn->GetPawnEnd());
//
//	// Solve normalized surface normal
//	FVector NormalizedSurfaceNormal = SurfaceNormal.GetSafeNormal();
//
//	// Solve d - p0
//	FVector Diff = RayOrigin - PlaneD;
//
//	// Solve ň
//	FVector DeltaNormal = RayDelta.GetSafeNormal();
//
//	// Solve numerator (d - p0*n)
//	//float numerator = -MyMathLibrary::DotProduct(Diff, NormalizedSurfaceNormal);
//	float numerator = -1 * (FVector::DotProduct(Diff, NormalizedSurfaceNormal));
//
//	// Solve ň*n
//	//float denominator = MyMathLibrary::DotProduct(DeltaNormal, NormalizedSurfaceNormal);
//	float denominator = FVector::DotProduct(DeltaNormal, NormalizedSurfaceNormal);
//
//	// If denominator is zero, then ray is parallel to the plane
//	// and there is no intersection
//	if (denominator == 0.f)
//	{
//		GEngine->AddOnScreenDebugMessage(
//			1, 30.f, FColor::Red
//			, TEXT("\nRay parallel to plane! No intersection!, GeometricTestLibrary.h:856\n"));
//
//		return Result;
//	}
//
//	// Solve d - p0*n / ň*n
//	float t = numerator / denominator;
//
//	// Solve R, the parametric ray
//	FVector R = RayOrigin + (DeltaNormal*t);
//
//	// TODO: Allow intersection only with front of plane (i.e., denominator < 0)
//	// Thus, intersection only if the ray points in a direction opposite 
//	// to the normal of the plane.
//
//	// Return true if t is within range
//	// If t < 0 or t > length of ray, intersection does not occur
//
//	if (t < 0 || t > R.Size())
//	{
//		GEngine->AddOnScreenDebugMessage(
//			1, 30.f, FColor::Red
//			, TEXT("\nFAILURE! No intersection!, GeometricTestLibrary.h:877\n"));
//
//		Result = false;
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(
//			1, 30.f, FColor::Red
//			, TEXT("\nSUCCESS! Ray and Plane intersect!, GeometricTestLibrary.h:885\n"));
//
//		Result = true;
//	}
//
//	return Result;
//}

