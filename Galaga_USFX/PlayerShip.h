
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

UCLASS()
class GALAGA_USFX_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	APlayerShip();

	// Método para mover la nave
	void MoveRight(float Value);

protected:
	// Propiedades de la nave
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	class UStaticMeshComponent* ShipMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	float MoveSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	float MaxMoveSpeed;
};
