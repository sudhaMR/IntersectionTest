// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "IntersectionTestsGameMode.h"
#include "IntersectionTestsPawn.h"
#include "IntersectionTestsHud.h"

AIntersectionTestsGameMode::AIntersectionTestsGameMode()
{
	DefaultPawnClass = AIntersectionTestsPawn::StaticClass();
	HUDClass = AIntersectionTestsHud::StaticClass();
}
