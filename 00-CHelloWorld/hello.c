#include <stdio.h>

int main(void){

    FILE *punteroAlArchivo;

    punteroAlArchivo = fopen("output.txt", "w");

    fprintf(punteroAlArchivo, "%s", "Hello World!");

    printf("Hello World\n");

    fclose(punteroAlArchivo);

    return 0;
}