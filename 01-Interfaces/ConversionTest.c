#include <assert.h>
#include <stdio.h> 
#include "Conversion.h" // ConversionTest.c Importa a la Interfaz Conversion.h

int main(void){

    const int gradosFahrenheit = 50, gradosCelsius = 150;

    const float resultadoCelsius = ((gradosFahrenheit - 32.0) * (5.0/9.0)), resultadoFahrenheit = ( (gradosCelsius * (9.0/5.0)) + 32.0);
    
    // Usando las formulas, le asigno a dos constantes los resultados de convertir 50 F a Celsius y 150 C a Fahrenheit para verificar que coinciden con los resultados de mis funciones fahrenheit y celsius.

    assert(celsius(gradosFahrenheit) == resultadoCelsius); // 50 F = 10 C

    assert(fahrenheit(gradosCelsius) == resultadoFahrenheit); // 150 C = 302 F

    // Si al ejecutar ConversionTest.c no se imprime nada por consola, los test pasaron.

    return 0;
}






