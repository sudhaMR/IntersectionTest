// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "IntersectionTestsHud.generated.h"


UCLASS(config = Game)
class AIntersectionTestsHud : public AHUD
{
	GENERATED_BODY()

public:
	AIntersectionTestsHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface
};
