// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandsOfTheVoid.h"
#include "SpellMaster.h"


// Sets default values
ASpellMaster::ASpellMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpellMaster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpellMaster::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

