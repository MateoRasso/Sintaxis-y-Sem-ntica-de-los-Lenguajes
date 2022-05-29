#include <assert.h>
#include <stdio.h> 
#include "Conversion.h" // ConversionTest.c Importa a la Interfaz Conversion.h

int main(void){

    const int limiteInferior =  0, limiteSuperiror = 300, incremento = 20;

    for(double gradosFahrenheit = limiteInferior; gradosFahrenheit <= limiteSuperiror; gradosFahrenheit += incremento){

        //printf("Fahrenheit: %f \t Fahrenheit convertido a Celsius y convertido a Fahrenheit de nuevo: %f \n", gradosFahrenheit, fahrenheit(celsius(gradosFahrenheit)));
        
        assert(gradosFahrenheit == fahrenheit(celsius(gradosFahrenheit))); // Verifico que la salida de la funcion "fahrenheit" coincida con el argumento que le paso a la funcion "celsius".
        // Este assert falla porque: 0° F es distinto de fahrenheit(celsius(0° F))   
    }

    for(double gradosCelsius = limiteInferior; gradosCelsius <= limiteSuperiror; gradosCelsius += incremento){

        //printf("Celsius: %f \t Celsius convertido a Fahrenheit y convertido a Celsius de nuevo: %f \n", gradosCelsius, fahrenheit(celsius(gradosCelsius)));

        assert(gradosCelsius == celsius(fahrenheit(gradosCelsius))); // Verifico que la salida de la funcion "celsius" coincida con el argumento que le paso a la funcion "fahrenheit".
        // Este assert tambien deberia fallar como el de la linea 13, ya que 0° C es distinto de celsius(fahrenheit(0° C)) , pero por algun motivo no falla.
    }

    return 0;
}






