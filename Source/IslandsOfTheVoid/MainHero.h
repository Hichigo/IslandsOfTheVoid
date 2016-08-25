// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MainHero.generated.h"

UCLASS(Blueprintable)
class ISLANDSOFTHEVOID_API AMainHero : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainHero();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	/* Calculate direction character */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Locomotion)
	float GetDirection();

	/* Returns TopDownCameraComponent subobject */
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/* Returns CameraBoom subobject */
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/* Look player vector */
	FVector TargetLook;

	/* Player controller */
	APlayerController* PC;

	/* Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;
	
	/* Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/* Skeletal Mesh head equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Head;
	
	/* Skeletal Mesh chest equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Chest;

	/* Skeletal Mesh belt equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Belt;

	/* Skeletal Mesh pants equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Pants;

	/* Skeletal Mesh boots equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Boots;

	/* Skeletal Mesh neck equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Neck;

	/* Skeletal Mesh shoulder equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Shoulder;

	/* Skeletal Mesh gloves equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_Gloves;

	/* Skeletal Mesh ring right equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_RingRight;

	/* Skeletal Mesh ring left equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_RingLeft;

	/* Skeletal Mesh right hand equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_RightHand;

	/* Skeletal Mesh lefy hand equipment */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EquipMesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *SM_LeftHand;
};

