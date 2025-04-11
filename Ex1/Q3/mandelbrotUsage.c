#include "mandelbrotLib.h"
#include <stdio.h>
#include <math.h>


int main(){
    printf("Please enter a comlex number (real and imaginary):\n");
    double real;
    double imaginary;

    int N = 1000; // Default value

    while (true) {
        scanf("%lf%lf", &real, &imaginary);

        double complex c = real + imaginary * I;

        if (real == 0 && imaginary == 0) {
            printf("The number is in the set\n");
            printf("Exiting the program...\n");
            break;
        }

        if (is_in_mandelbrot(c,N)){
            printf("The number is in the set\n");
        } else {
            printf("The number is not in the set\n");

        }
        
    }

    return 0;
    
}