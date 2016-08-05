// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "IslandsOfTheVoid.h"
#include "IslandsOfTheVoidGameMode.h"
#include "IslandsOfTheVoidPlayerController.h"
#include "IslandsOfTheVoidCharacter.h"

AIslandsOfTheVoidGameMode::AIslandsOfTheVoidGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AIslandsOfTheVoidPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}