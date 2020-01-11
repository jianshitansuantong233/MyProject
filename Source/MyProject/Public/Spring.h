// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Spring.generated.h"

UCLASS()
class MYPROJECT_API ASpring : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpring();

	UFUNCTION(BlueprintCallable)
	int nextState(int curState, int key) { return m_states_table[key][curState]; }

	UFUNCTION(BlueprintCallable)
	int nextAnim(int curState, int key) { return m_animation_table[key][curState]; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	const int m_animation_table[3][14] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {1,2,3,4,0,7,8,0,0,13,14,0,0,0}, {0,0,5,11,6,9,0,10,12,0,0,15,16,17} };
	const int m_states_table[3][14] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {1,2,3,0,0,6,0,0,0,10,11,0,0,0}, {0,0,4,8,5,7,0,0,9,0,0,12,13,0} };

};
