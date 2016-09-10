// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Classes/SpellData.h"
#include "GameFramework/Actor.h"
#include "SpellMaster.generated.h"

UCLASS()
class ISLANDSOFTHEVOID_API ASpellMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpellMaster();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/* A pointer to spell data information*/
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Spell Info")
	class USpellData *SpellDataInfo;

	/* Get information about spell*/
	UFUNCTION(BlueprintCallable, Category = "Spell Info")
	FORCEINLINE FSpellInfo GetData() const { return SpellDataInfo->Data; };
	
};
