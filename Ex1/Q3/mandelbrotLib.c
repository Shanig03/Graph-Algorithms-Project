#include <stdio.h>
#include <stdbool.h>
#include <complex.h>
#include "mandelbrotLib.h"



bool is_in_mandelbrot_helper(double complex c, int N){
    double complex z = 0;
    for (int i = 0; i < N; ++i) {
        z = z * z + c;
        if (cabs(z) > 2.0) return 0;
    }
    return 1;
}

bool is_in_mandelbrot(double complex c, int N){

    if (is_in_mandelbrot_helper(c, N)) {
        return 1;
    } else {
        double complex z = 0;
        int diverged = 0;

        for (int i = 0; i < 10000; ++i) {
            z = z * z + c;
            if(cabs(z) > 2.0){
                diverged = 1;
                break;
            }
        }

        if (!diverged) { 
            return 0;
        } else {
            return 0;
        }
    }
    return 0;
}

