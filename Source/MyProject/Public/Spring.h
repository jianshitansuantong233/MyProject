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
	const int m_states_table[3][15] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {1,2,3,0,5,0,8,0,9,0,0,0,13,14,0}, {0,4,6,11,0,0,7,0,10,0,0,12,0,0,0} };
	const int m_animation_table[3][15] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, {1,2,3,4,6,0,11,0,12,13,0,0,18,19,0}, {0,5,8,16,0,7,9,10,14,0,15,17,0,0,20} };
	

};
