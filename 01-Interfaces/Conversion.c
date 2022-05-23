#include <stdio.h>
#include "Conversion.h"


float celsius(float farenheitDegrees){ // Convierte a grados Celsius

    float celsiusDegrees;
        
    return celsiusDegrees = (farenheitDegrees - 32.0) * (5.0/9.0);
}

float farenheit(float celsiusDegrees){ // Convierte a grados Farenheit

    float farenheitDegrees;
        
    return farenheitDegrees = (celsiusDegrees * (9.0/5.0)) + 32.0;
}

