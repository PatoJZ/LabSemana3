#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_jugadores 10
#define MAX_jugadores_POR_EQUIPO 5

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
        if (jugadores_por_equipo[jugadores[i].equipo - 1] >= MAX_jugadores_POR_EQUIPO) {
            printf("Error: número máximo de jugadores (%d) para el equipo %d alcanzado\n", MAX_jugadores_POR_EQUIPO, jugadores[i].equipo);
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
void determinarGanador(Jugador *jugadores, int n) {
    int equipo1_puntaje = 0, equipo2_puntaje = 0;
    for (int i = 0; i < n; i++) {
        if (jugadores[i].equipo == 1) {
            equipo1_puntaje += jugadores[i].puntaje;
        } else {
            equipo2_puntaje += jugadores[i].puntaje;
        }
    }
        if (equipo1_puntaje > equipo2_puntaje) {
            printf("El equipo 1 es el ganador con un puntaje total de %d\n", equipo1_puntaje);
        } else if (equipo2_puntaje > equipo1_puntaje) {
            printf("El equipo 2 es el ganador con un puntaje total de %d\n", equipo2_puntaje);
        } else {
            printf("Empate entre los equipos con un puntaje total de %d\n", equipo1_puntaje);
        }
}
void verEstadisticas(Jugador *jugadores, int n, char *nombre) {
    for (int i = 0; i < n; i++) {
        // Si el nombre del jugador es igual al nombre buscado
        // Genera los print de todas las caracteristicas
        if (strcmp(jugadores[i].nombre, nombre) == 0) {
            printf("Estadísticas para %s:\n", jugadores[i].nombre);
            printf("Nivel: %d\n", jugadores[i].nivel);
            printf("Salud: %d\n", jugadores[i].salud);
            printf("Puntaje: %d\n", jugadores[i].puntaje);
            return;
        }
    }
    printf("Error: jugador no encontrado\n");
}
void actualizarEstadisticas(Jugador *jugadores, int n, char *nombre, int nivel, int salud, int puntaje) {
    for (int i = 0; i < n; i++) {
        // Si el nombre del jugador es igual al nombre buscado
        // Se reemplaza los datos metidos por el usuario en las caracteristicas del jugador
        if (strcmp(jugadores[i].nombre, nombre) == 0) {
            printf("Estadísticas actualizadas para %s:\n", jugadores[i].nombre);
            jugadores[i].nivel = nivel;
            jugadores[i].salud = salud;
            jugadores[i].puntaje = puntaje;
            printf("Nivel: %d\n", jugadores[i].nivel);
            printf("Salud: %d\n", jugadores[i].salud);
            printf("Puntaje: %d\n", jugadores[i].puntaje);
            return;
        }
    }
    printf("Error: jugador no encontrado\n");
}

int main() {
    Jugador jugadores[MAX_jugadores];
    int n;
    char nombre_actualizar[100];
    int nivel_actualizar, salud_actualizar, puntaje_actualizar;
    

    printf("Ingrese el número de jugadores a ingresar (máximo %d): ", MAX_jugadores);
    scanf("%d", &n);

    if (n > MAX_jugadores) {
        printf("Error: número de jugadores a ingresar supera el máximo permitido de %d\n", MAX_jugadores);
        return 1;
    }

    ingresarDatos(jugadores, n);

    mostrarDatos(jugadores, n);

    printf("Ingrese el nombre del jugador a actualizar: ");
    scanf("%s", nombre_actualizar);
    printf("Ingrese el nuevo nivel del jugador: ");
    scanf("%d", &nivel_actualizar);
    printf("Ingrese la nueva salud del jugador: ");
    scanf("%d", &salud_actualizar);
    printf("Ingrese el nuevo puntaje del jugador: ");
    scanf("%d", &puntaje_actualizar);

    actualizarEstadisticas(jugadores, n, nombre_actualizar, nivel_actualizar, salud_actualizar, puntaje_actualizar);

    determinarGanador(jugadores, n);

    return 0;
}


