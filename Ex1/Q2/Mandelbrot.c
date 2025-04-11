#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

void printUsage(const char* programName){
    fprintf(stderr, "Usage: %s <real> <imagimary> [N]\n", programName);
    fprintf(stderr, "Example: %s -0.5 0.5 1000\n", programName);
}


int isInMandelbrotSet(double complex c, int N, double M){
    double complex z = 0;
    for(int i = 0; i < N; ++i){
        z = z * z + c; // Calculate by the formula
        if(cabs(z) > M){ // Calculate the absolute value of z
            return 0; // Not in the set
        }
    }
    return 1;
}


int main(int argc, char* argv[]) {
    if(argc < 3) {
        printUsage(argv[0]);
        return 1;
    }

    double real = atof(argv[1]);
    double imaginary = atof(argv[2]);
    double M = 2.0;

    int N;
    if (argc >= 4) {
        N = atoi(argv[3]);
    } else {
        N = 1000; // Default value
    }

    double complex c = real + imaginary * I;

    if (isInMandelbrotSet(c, N, M)) {
        printf("The number is in the set\n");
    } else {
        double complex z = 0;
        int diverged = 0;

        for (int i = 0; i < 10000; ++i) {
            z = z * z + c;
            if(cabs(z) > M){
                diverged = 1;
                break;
            }
        }

        if (!diverged) { 
            printf("The number is not in the set, but the N is too small and the ...\n");
        } else {
            printf("The number is not in the set\n");
        }
    }
    return 0;
}