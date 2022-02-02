// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleProp.h"
#include "Engine.h"

// Sets default values
ADestructibleProp::ADestructibleProp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Allow attachment onto scene component and ignore the state of the destructible component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));

	DestructibleComponent = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Destructible Component"));
	DestructibleComponent->SetupAttachment(RootComponent);
	DestructibleComponent->SetNotifyRigidBodyCollision(true);

	TriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Component"));
	TriggerComponent->SetupAttachment(RootComponent);

	IsDestroyed = false;
	IsTriggerEnabled = false;

	MaxHealth = 1.0f;
	DefaultDamage = 1.f;
	DefaultImpulse = 1.f;

}

// Called when the game starts or when spawned
void ADestructibleProp::BeginPlay()
{
	Super::BeginPlay();

	DestructibleComponent->OnComponentHit.AddDynamic(this, &ADestructibleProp::Damage);

	TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &ADestructibleProp::Trigger);
	
	CurrentHealth = MaxHealth;
}

void ADestructibleProp::Damage(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, __FUNCTION__);

	//Other Component(s) should be tagged with Weapon
	if (!IsDestroyed && OtherComp->ComponentHasTag("Weapon"))
	{
		CurrentHealth -= 1.f;
		if (CurrentHealth <= 0.f)
		{
			Destroy(DefaultDamage, Hit.Location, NormalImpulse, DefaultImpulse);
		}
	}
}

void ADestructibleProp::Trigger(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, __FUNCTION__);

	if (!IsDestroyed && IsTriggerEnabled && OtherActor->ActorHasTag("Player"))
	{
		Destroy(DefaultDamage, DestructibleComponent->GetComponentLocation(),DestructibleComponent->GetForwardVector(),DefaultImpulse);
	}
}

void ADestructibleProp::Destroy(float Damage, FVector HitLocation, FVector ImpulseDir, float Impulse)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, __FUNCTION__);

	if (!IsDestroyed)
	{
		IsDestroyed = true;

		DestructibleComponent->ApplyDamage(Damage, HitLocation, ImpulseDir, Impulse);
	}

}

// Called every frame
void ADestructibleProp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

