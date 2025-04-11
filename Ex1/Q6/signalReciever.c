#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

unsigned char recieved_number = 0;
int bit_count = 0;


void signal_handler(int signal){
    if (signal == SIGUSR1){
        recieved_number &= ~(1 << (7 - bit_count));
    } else if (signal == SIGUSR2){
        recieved_number |= (1 << (7 - bit_count));
    }
    
    bit_count++;

    if (bit_count == 8){
        printf("Recieved %d\n", recieved_number);
        exit(0);
    }
}



int main(){
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    printf("My PID is: %d\n", getpid());

    while (1){
        pause();
    }
    
    return 0;
}