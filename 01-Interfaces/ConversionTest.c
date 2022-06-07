#include <assert.h>
#include <stdio.h> 
#include <stdlib.h> // Incluimos el acrhivo header stdlib.h Para usar abs()
#include "Conversion.h" // ConversionTest.c Importa a la Interfaz Conversion.h

int main(void){

    const int limiteInferior =  0, limiteSuperiror = 300, incremento = 20;

    const double error = 0.00000001;

    for(double gradosFahrenheit = limiteInferior; gradosFahrenheit <= limiteSuperiror; gradosFahrenheit += incremento){

        //printf("Fahrenheit: %f \t Fahrenheit convertido a Celsius y convertido a Fahrenheit de nuevo: %f \n", gradosFahrenheit, fahrenheit(celsius(gradosFahrenheit)));
        
        assert(abs(fahrenheit(celsius(gradosFahrenheit)) - gradosFahrenheit) < error);  // Verifico que la diferencia entre los grados Faherenheit y los grados Farenheit convertidos a celsius y de nuevo a Fahrenheit sea menor a un error determinado

    }

    for(double gradosCelsius = limiteInferior; gradosCelsius <= limiteSuperiror; gradosCelsius += incremento){

        //printf("Celsius: %f \t Celsius convertido a Fahrenheit y convertido a Celsius de nuevo: %f \n", gradosCelsius, fahrenheit(celsius(gradosCelsius)));

        assert(abs(celsius(fahrenheit(gradosCelsius)) - gradosCelsius) < error); // Verifico que la diferencia entre los grados Celsius y los grados Celsius convertidos a Fahrenheit y de nuevo a Celsius sea menor a un error determinado.
        
    }

    return 0;
}






