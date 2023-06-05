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
}

int main() {
    float calificaciones[NUM_ALUMNOS][NUM_UNIDADES];
    float promedios[NUM_ALUMNOS];

    srand(time(NULL));

    for (int i = 0; i < NUM_ALUMNOS; i++) {
        for (int j = 0; j < NUM_UNIDADES; j++) {
            calificaciones[i][j] = generarCalificacion();
        }
        promedios[i] = obtenerPromedio(calificaciones[i]);
    }

    float mayorNota = obtenerMayorNota(calificaciones[0]);
    for (int i = 1; i < NUM_ALUMNOS; i++) {
        float nota = obtenerMayorNota(calificaciones[i]);
        if (nota > mayorNota) {
            mayorNota = nota;
        }
    }

    
    int examenMayorPromedio = obtenerExamenMayorPromedio(promedios);


    printf("Promedio de calificaciones por Estudiante:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promedios[i]);
    }
    printf("\n");
    printf("Mayor nota del semestre: %.2f\n", mayorNota);
    printf("Examen con mayor promedio de calificación: Examen %d\n", examenMayorPromedio);

    return 0;
}
