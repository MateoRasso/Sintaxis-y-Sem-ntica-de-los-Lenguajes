#include <stdio.h>
#include "Conversion.h"

void printTables(const int, const int, const int);

int main(void){

    const int lowerLimit = 0, upperLimit = 300, step = 12;

    printTables(lowerLimit, upperLimit, step);

    return 0;
}

void printTables(const int lowerLimit, const int upperLimit, const int step){

    printf("Farenheit a Celsius \t\t Celsius a Farenheit \n\n");

    for(int degrees = lowerLimit; degrees < upperLimit; degrees += step){
        printf("%d F -> %f C \t\t %d C -> %f F \n", degrees, celsius(degrees), degrees, farenheit(degrees));
    }

}