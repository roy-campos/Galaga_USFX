
#include "PlayerShip.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

APlayerShip::APlayerShip()
{
	// Configuraci�n del mesh de la nave
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMesh;

	// Configuraci�n del movimiento
	MoveSpeed = 500.0f;
	MaxMoveSpeed = 1000.0f;

	// Establecer las reglas de replicaci�n para el multiplayer (si es necesario)
	bReplicates = true;
	bReplicateMovement = true;
}

void APlayerShip::MoveRight(float Value)
{
	// Mover la nave hacia la derecha o izquierda seg�n el valor proporcionado
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + FVector(0.0f, Value * MoveSpeed * GetWorld()->GetDeltaSeconds(), 0.0f);

	// Limitar la posici�n de la nave dentro de la pantalla
	NewLocation.Y = FMath::Clamp(NewLocation.Y, -MaxMoveSpeed, MaxMoveSpeed);

	SetActorLocation(NewLocation);
}

void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Configurar los controles de entrada
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerShip::MoveRight);
}
