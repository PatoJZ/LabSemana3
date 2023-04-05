#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_jugadores 10
#define MAX_JUGADORES_POR_EQUIPO 5

typedef struct {
    char nombre[100];
    int nivel;
    int salud;
    int puntaje;
    int equipo;  // Nuevo campo para diferenciar los equipos
} Jugador;

void ingresarDatos(Jugador *jugadores, int n) {
    int jugadores_por_equipo[2] = {0};  // Contador de jugadores por equipo
    for (int i = 0; i < n; i++) {
        printf("Ingrese los datos para el Jugador %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", jugadores[i].nombre);

        printf("Nivel: ");
        scanf("%d", &jugadores[i].nivel);

        printf("Salud: ");
        scanf("%d", &jugadores[i].salud);

        printf("Puntaje: ");
        scanf("%d", &jugadores[i].puntaje);

        printf("Equipo (1 o 2): ");
        scanf("%d", &jugadores[i].equipo);

        // Verificar si el número de jugadores en el equipo actual ha sido alcanzado
        if (jugadores_por_equipo[jugadores[i].equipo - 1] >= MAX_JUGADORES_POR_EQUIPO) {
            printf("Error: número máximo de jugadores (%d) para el equipo %d alcanzado\n", MAX_JUGADORES_POR_EQUIPO, jugadores[i].equipo);
            i--;  // Volver a ingresar los datos para el Jugador actual
        } else {
            jugadores_por_equipo[jugadores[i].equipo - 1]++;  // Incrementar el contador de jugadores por equipo
        }
    }
}


void mostrarDatos(Jugador *jugadores, int n) {
    printf("jugadores:\n");
    for (int i = 0; i < n; i++) {
        printf("Nombre: %s\n", jugadores[i].nombre);
        printf("Nivel: %d\n", jugadores[i].nivel);
        printf("Salud: %d\n", jugadores[i].salud);
        printf("Puntaje: %d\n", jugadores[i].puntaje);
        printf("Equipo: %d\n", jugadores[i].equipo);
        printf("\n");
    }
}

int main() {
    Jugador jugadores[MAX_jugadores];
    int n;

    printf("Ingrese el número de jugadores a ingresar (máximo %d): ", MAX_jugadores);
    scanf("%d", &n);

    if (n > MAX_jugadores) {
        printf("Error: número de jugadores a ingresar supera el máximo permitido de %d\n", MAX_jugadores);
        return 1;
    }

    ingresarDatos(jugadores, n);

    mostrarDatos(jugadores, n);

    return 0;
}


