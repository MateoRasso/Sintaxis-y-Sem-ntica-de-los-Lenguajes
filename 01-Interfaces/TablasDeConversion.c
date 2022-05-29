#include <stdio.h>
#include "Conversion.h" // TablasDeConversion.c Importa a la Interfaz Conversion.h

void printTablas(const int, const int, const int);

void printTablaCelsius(const int, const int, const int);

void printTablaFahrenheit(const int, const int, const int);

int main(void){

    const int limiteInferior = 0, limiteSuperior = 300, incremento = 20;

    printTablas(limiteInferior, limiteSuperior, incremento);

    //printTablaCelsius(limiteInferior, limiteSuperior, incremento);

    //printTablaFahrenheit(limiteInferior, limiteSuperior, incremento);

    return 0;
}

void printTablas(const int limiteInferior, const int limiteSuperior, const int incremento){

    printTablaCelsius(limiteInferior, limiteSuperior, incremento);

    printTablaFahrenheit(limiteInferior, limiteSuperior, incremento);
    
    return;
}

void printTablaCelsius(const int limiteInferior, const int limiteSuperior, const int incremento){

    printf("\nFahrenheit a Celsius \n");

    for(double gradosFahrenheit = limiteInferior; gradosFahrenheit <= limiteSuperior; gradosFahrenheit += incremento){
        printf("%f F -> %f C \n", gradosFahrenheit, celsius(gradosFahrenheit)); 
    }

    return;
}

void printTablaFahrenheit(const int limiteInferior, const int limiteSuperior, const int incremento){

    printf("\nCelsius a Fahrenheit \n");
    
    for(double gradosCelsius = limiteInferior; gradosCelsius <= limiteSuperior; gradosCelsius += incremento){
        printf("%f C -> %f F \n", gradosCelsius, fahrenheit(gradosCelsius)); 
    }

    return;
}