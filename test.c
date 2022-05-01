#include <stdio.h>

void funcionUno(int *a);
void funcionDos(int *a);
void funcionTres(int **a);

int main(int argc, char const *argv[])
{
    int testUno = 5;

    int testDos[3];
    testDos[0] = 1;
    testDos[1] = 1;
    testDos[2] = 1;

    int testTres[2][2];

    funcionUno(&testUno); // pide un puntero, un puntero tiene una direccion, le pasamos una direccion directamente
    funcionDos(testDos); // pide lo mismo, pero la cabecera es una direccion, pasamos la cabecera
    funcionTres(testTres[0]);

    printf("\nvalor simple: %d", testUno);
    printf("\nvalor matriz: %d", testDos[0]);
    printf("\nvalor matriz: %d", testDos[1]);
    printf("\nvalor matriz: %d", testDos[2]);
    printf("\nvalor matrizD: %d", testTres[0][0]);
    printf("\nvalor matrizD: %d", testTres[0][1]);
    

    return 0;
}

void funcionUno(int *a){
    *a = 10;
}

void funcionDos(int *a){
    a[1]=10;
}

void funcionTres(int **a){
    *a = 5;
}
