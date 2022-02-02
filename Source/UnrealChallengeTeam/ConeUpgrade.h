// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"UpgradableCharacter.h"
#include "ConeUpgrade.generated.h"

UCLASS()
class UNREALCHALLENGETEAM_API AConeUpgrade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConeUpgrade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite) AUpgradableCharacter* playerCharacter;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) class UBoxComponent* CollisionBox;

	UFUNCTION() void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable) void ConfirmAssignment();
};