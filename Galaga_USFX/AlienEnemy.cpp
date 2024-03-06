// AlienEnemy.cpp

#include "AlienEnemy.h"

AAlienEnemy::AAlienEnemy()
{
	// Configuraci�n del mesh del enemigo
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	RootComponent = EnemyMesh;

	// Configuraci�n del movimiento
	MoveSpeed = 100.0f; // Ajusta la velocidad seg�n tus necesidades
}

void AAlienEnemy::MoveDown()
{
	// Mover el enemigo hacia abajo en el eje Z
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation - FVector(0.0f, 0.0f, MoveSpeed * GetWorld()->GetDeltaSeconds());

	SetActorLocation(NewLocation);
}
