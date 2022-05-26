#include <stdio.h>
#include "Conversion.h" // Conversion.c exporta a la Interfaz Conversion.h


float celsius(int gradosFahrenheit){ // Convierte a grados Celsius
        
    return ((gradosFahrenheit - 32.0) * (5.0/9.0)); // Antes de realizar la resta los gradosFahrenheit son convertidos de int a float
}

float fahrenheit(int gradosCelsius){ // Convierte a grados Fahrenheit
        
    return ((gradosCelsius * (9.0/5.0)) + 32.0); // Antes de realizar la resta los gradosCelsius son convertidos de int a float
}

