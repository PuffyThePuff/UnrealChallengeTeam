// Fill out your copyright notice in the Description page of Project Settings.


#include "ConeUpgrade.h"
#include"Components/BoxComponent.h"
#include"Engine/Engine.h"

// Sets default values
AConeUpgrade::AConeUpgrade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConeUpgrade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AConeUpgrade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConeUpgrade::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

}

void AConeUpgrade::ConfirmAssignment() {
	UE_LOG(LogTemp, Display, TEXT("Found the player character."));
}