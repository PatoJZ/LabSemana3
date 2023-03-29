#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


 typedef struct { 
        char Nombre[20];
        int Nivel;
        int Salud;
        int Puntaje;
    }personaje;
void crearPersonaje(personaje *p){
    printf("Ingrese el nombre: ");
    personaje -> malloc(strlen(p->Nombre) + 1);
    printf("Ingrese el nivel: ");
    scanf("%d",&p->Nivel);
    printf("Ingrese el salud: ");
    scanf("%d",&p->Salud);
    printf("Ingrese el puntaje: ");
    scanf("%d",&p->Puntaje);
}
void mostrarPersonaje(personaje *p){
    printf("Nombre: %s\n", p -> Nombre);
    printf("Nivel: %d\n",p -> Nivel);
    printf("Salud: %d\n",p -> Salud);
    printf("Puntaje: %d\n",p ->Puntaje);
}
int main(){
    personaje *p[3];
    for (int i = 0; i < 2; i++){
        crearPersonaje(&p[i])
    }
    
    return 0;

}

