#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int* arr, int size, int seed){
    srand(seed);
    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % 100) - 25; // Between -25 to 74
    }
}

int max_sub_array_n3(int* arr, int size){
    int max_sum = arr[0];
    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j){
            int sum = 0;
            for (int k = i; k <= j; ++k){
                sum += arr[k];
                if (sum > max_sum){
                    max_sum = sum;
                }
            }
        }
    }
    return max_sum;
}

int max_sub_array_n2(int* arr, int size){
    int max_sum = arr[0];
    for (int i = 0; i < size; i++){
        int sum = 0;
        for (int j = i; j < size; ++j){
            sum += arr[j];
            if (sum > max_sum){
                max_sum = sum;
            }
            
        }
    }
    return max_sum;
}

int max_sub_array_n(int* arr, int size){
    int max_sum = arr[0];
    int current_sum = arr[0];
    for (int i = 1; i < size; ++i){
        current_sum = (arr[i] > arr[i] + current_sum) ? arr[i] : arr[i] + current_sum;
        if (current_sum > max_sum){
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int main(int argc, char* argv[]){

    if(argc != 3){
        printf("Usage: %s <size> <seed>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]);
    int seed = atoi(argv[2]);

    int* arr = malloc(size * sizeof(int));
    if(!arr){
        perror("Malloc failed\n");
        return 1;
    }

    generate_random_array(arr, size, seed);

    int ans1 = max_sub_array_n3(arr, size);
    printf("max sub array n^3 = %d\n",ans1);

    int ans2 = max_sub_array_n2(arr, size);
    printf("max sub array n^2 = %d\n",ans2);

    int ans3 = max_sub_array_n(arr, size);
    printf("max sub array n^1 = %d\n",ans3);


    free(arr);
 
    
    

    return 0;
}