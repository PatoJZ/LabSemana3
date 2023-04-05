#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUGADORES 100

typedef struct {
    char nombre[100];
    int nivel;
    int salud;
    int puntaje;
} Jugador;

void ingresarDatos(Jugador *Jugadores, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese los datos para el personaje %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", Jugadores[i].nombre);

        printf("Nivel: ");
        scanf("%d", &Jugadores[i].nivel);

        printf("Salud: ");
        scanf("%d", &Jugadores[i].salud);

        printf("Puntaje: ");
        scanf("%d", &Jugadores[i].puntaje);
    }
}

void mostrarDatos(Jugador *Jugadores, int n) {
    for (int i = 0; i < n; i++) {
        printf("Datos del personaje %d:\n", i + 1);
        printf("Nombre: %s\n", Jugadores[i].nombre);
        printf("Nivel: %d\n", Jugadores[i].nivel);
        printf("Salud: %d\n", Jugadores[i].salud);
        printf("Puntaje: %d\n", Jugadores[i].puntaje);
    }
}
int main() {
    Jugador Jugadores[MAX_JUGADORES];
    int n;

    printf("Ingrese el número de Jugadores a ingresar: ");
    scanf("%d", &n);

    ingresarDatos(Jugadores, n);

    mostrarDatos(Jugadores, n);

    return 0;
}

