// AlienEnemy.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlienEnemy.generated.h"

UCLASS()
class GALAGA_USFX_API AAlienEnemy : public AActor
{
	GENERATED_BODY()

public:
	AAlienEnemy();

	// Método para mover el enemigo
	void MoveDown();

protected:
	// Propiedades del enemigo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AlienEnemy")
	class UStaticMeshComponent* EnemyMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AlienEnemy")
	float MoveSpeed;
};
