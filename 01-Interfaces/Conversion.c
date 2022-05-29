#include <stdio.h>
#include "Conversion.h" // Conversion.c exporta a la Interfaz Conversion.h


double celsius(double gradosFahrenheit){ // Convierte a grados Celsius
        
    return ((gradosFahrenheit - 32.0) * (5.0/9.0)); // Si gradosFahrenheit es int, es convertido a double antes de realizar la operacion.
}

double fahrenheit(double gradosCelsius){ // Convierte a grados Fahrenheit
        
    return ((gradosCelsius * (9.0/5.0)) + 32.0); // Si gradosCelsius es int, es convertido a double antes de realizar la operacion.
}

