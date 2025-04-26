#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5 
#define M 7 

int main(){
    srand(time(NULL));
    int i,j; 
    int mt[N][M]; 
    int *p = &mt[0][0];//apuntamos al primer elemento de la matriz

    for(i = 0;i<N; i++) {  
        for(j = 0;j<M; j++) { 
            *(p + i*M + j)=1+rand()%100; //modificamos el contenido de la direcc, con +i*M se ubica en la fila, y con +j en la columna
            printf("%d   ", *(p+i*M+j)); //mostramos
        } 
    printf("\n"); 
    }
    return 0;
}
