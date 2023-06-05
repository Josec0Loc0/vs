#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALUMNOS 23
#define NUM_UNIDADES 3


int generarCalificacion() {
    return rand() % 10 + 1; 

}

float obtenerPromedio(float calificaciones[]) {
    float suma = 0.0;
    for (int i = 0; i < NUM_UNIDADES; i++) {
        suma += calificaciones[i];
    }
    return suma / NUM_UNIDADES;
}


float obtenerMayorNota(float calificaciones[]) {
    float mayorNota = calificaciones[0];
    for (int i = 1; i < NUM_UNIDADES; i++) {
        if (calificaciones[i] > mayorNota) {
            mayorNota = calificaciones[i];
        }
    }
    return mayorNota;
}


int obtenerExamenMayorPromedio(float promedios[]) {
    int examenMayorPromedio = 1;
    float mayorPromedio = promedios[0];
    for (int i = 1; i < NUM_UNIDADES; i++) {
        if (promedios[i] > mayorPromedio) {
            mayorPromedio = promedios[i];
            examenMayorPromedio = i + 1;
        }
    }
    return examenMayorPromedio;
