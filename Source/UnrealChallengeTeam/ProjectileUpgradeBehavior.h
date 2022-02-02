// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include"UpgradableCharacter.h"
#include "ProjectileUpgradeBehavior.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCHALLENGETEAM_API UProjectileUpgradeBehavior : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProjectileUpgradeBehavior();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable) void SpawnUpgrade();

	UPROPERTY(EditAnywhere) AActor* upgradeItem1;
	UPROPERTY(EditAnywhere) AActor* upgradeItem2;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};