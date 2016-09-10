// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "SpellData.generated.h"

UENUM()
enum class ETypeSpell : uint8
{
	Active,
	Passive,
	Aura
};

USTRUCT(BlueprintType)
struct FSpellInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Struct")
	FText SpellName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Struct")
	ETypeSpell Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell Struct")
	float Damage;
};
/**
 * 
 */
UCLASS()
class ISLANDSOFTHEVOID_API USpellData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSpellInfo Data;
	
};
