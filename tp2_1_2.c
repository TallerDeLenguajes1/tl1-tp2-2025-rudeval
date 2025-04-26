#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main(){
    srand(time(NULL));
    int i;
    double vt[N];
    double *pVt = vt; 
    for (int i = 0; i < N; i++)
    {
        *(pVt + i)=1+rand()%100; //accedo al contenido sumado a i
        printf("%f   ", *(pVt + i));
    }
    

    return 0;
}  