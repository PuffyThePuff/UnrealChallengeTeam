// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileUpgradeBehavior.h"

// Sets default values for this component's properties
UProjectileUpgradeBehavior::UProjectileUpgradeBehavior()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileUpgradeBehavior::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UProjectileUpgradeBehavior::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UProjectileUpgradeBehavior::SpawnUpgrade()
{
	int itemToSpawn = (int) FMath::FRandRange(0.f, 3.f);
	FActorSpawnParameters spawnParameters;
	AActor* upgradeItem;

	switch (itemToSpawn) {
	case 0:
		spawnParameters.Template = upgradeItem1;
		spawnParameters.Owner = this->GetOwner()->GetOwner();

		upgradeItem = this->GetOwner()->GetWorld()->SpawnActor<AActor>(upgradeItem1->GetClass(), spawnParameters);
		upgradeItem->AttachToActor(this->GetOwner()->GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
		upgradeItem->SetActorHiddenInGame(false);
		upgradeItem->SetActorLocation(this->GetOwner()->GetActorLocation());
		upgradeItem->SetActorRotation(this->GetOwner()->GetActorRotation());
		break;
	case 1:
		spawnParameters.Template = upgradeItem2;
		spawnParameters.Owner = this->GetOwner()->GetOwner();

		upgradeItem = this->GetOwner()->GetWorld()->SpawnActor<AActor>(upgradeItem2->GetClass(), spawnParameters);
		upgradeItem->AttachToActor(this->GetOwner()->GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
		upgradeItem->SetActorHiddenInGame(false);
		upgradeItem->SetActorLocation(this->GetOwner()->GetActorLocation());
		upgradeItem->SetActorRotation(this->GetOwner()->GetActorRotation());
		break;
	}
}

void UProjectileUpgradeBehavior::ConfirmTemplates()
{
	UE_LOG(LogTemp, Display, TEXT("Template confirmed."));
}