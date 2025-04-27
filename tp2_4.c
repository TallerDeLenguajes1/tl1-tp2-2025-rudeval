#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

typedef struct { 
    int velocidad;      
    // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           
    // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; 
    // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu; 
    // Tipo de procesador (apuntador a cadena de caracteres) 
}tCompu; 

void listarPCs(tCompu pcs[], int cantidad);
void mostrarMasVieja(tCompu pcs[], int cantidad);
void mostrarMasVeloz(tCompu pcs[], int cantidad);


int main()
{
    srand(time(NULL));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"}; 
    tCompu computadoras[MAX];

    for (int i = 0; i < 5; i++) //recorremos para los 5 elementos de computadoras
    {
        computadoras[i].velocidad = rand()%3+1;
        computadoras[i].anio = rand()%10 + 2015;
        computadoras[i].cantidad_nucleos = rand()%9 + 1;
        computadoras[i].tipo_cpu = tipos[rand()%6]; //guarda dirección de una palabra aleatoria del arreglo tipos
        //(no usa & porque tipos[x] ya es una direccion al primer caracter de la cadena)
        //!!!probar hacer tambien con malloc y strcpy
    }

    listarPCs(computadoras, MAX);
    mostrarMasVieja(computadoras, MAX);
    mostrarMasVeloz(computadoras, MAX);
    
    return 0;
}


void listarPCs(tCompu pcs[], int cantidad){
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nComputadora Nro %d", i+1);
        printf("\n\tVelocidad: %d", pcs[i].velocidad);
        printf("\n\tAnio: %d", pcs[i].anio);
        printf("\n\tCantidad de nucleos: %d", pcs[i].cantidad_nucleos);
        printf("\n\tTipo de procesador: %s", pcs[i].tipo_cpu); //pasa la direccion donde esta guardado ese tipo al %s
    }
    
}

void mostrarMasVieja(tCompu pcs[], int cantidad){
    int menor = 2025, indice;
    for (int i = 0; i < cantidad; i++)
    { 
        if (pcs[i].anio<menor)
        {
            menor = pcs[i].anio;
            indice = i;
        }
        
    }
    
    printf("\n----->PC mas vieja<-----");
    printf("\nComputadora Nro %d", indice+1);
        printf("\n\tVelocidad: %d", pcs[indice].velocidad);
        printf("\n\tAnio: %d", pcs[indice].anio);
        printf("\n\tCantidad de nucleos: %d", pcs[indice].cantidad_nucleos);
        printf("\n\tTipo de procesador: %s", pcs[indice].tipo_cpu); 

}


void mostrarMasVeloz(tCompu pcs[], int cantidad){
    int mayor = 0, indice;
    for (int i = 0; i < cantidad; i++)
    { 
        if (pcs[i].velocidad>mayor)
        {
            mayor = pcs[i].velocidad;
            indice = i;
        }
        
    }
    
    printf("\n----->PC mas veloz<-----");
    printf("\nComputadora Nro %d", indice+1);
        printf("\n\tVelocidad: %d", pcs[indice].velocidad);
        printf("\n\tAnio: %d", pcs[indice].anio);
        printf("\n\tCantidad de nucleos: %d", pcs[indice].cantidad_nucleos);
        printf("\n\tTipo de procesador: %s", pcs[indice].tipo_cpu); 
}

/*
void cargarPCs(tCompu pcs[], int cantidad, char tipos[][10]) {
    for (int i = 0; i < cantidad; i++) {
        pcs[i].velocidad = rand() % 3 + 1;
        pcs[i].anio = rand() % 10 + 2015;
        pcs[i].cantidad_nucleos = rand() % 8 + 1;
        
        int indice = rand() % 6;  // elijo un tipo de CPU al azar
        
        pcs[i].tipo_cpu = (char*) malloc((strlen(tipos[indice]) + 1) * sizeof(char));
        // reservo memoria justa para el string (+1 para el \0 final)
        
        if (pcs[i].tipo_cpu != NULL) {
            strcpy(pcs[i].tipo_cpu, tipos[indice]);
            // copio la cadena en el espacio nuevo
        } 
    }
}

for (int i = 0; i < MAX; i++) {
    free(computadoras[i].tipo_cpu);
}

*/