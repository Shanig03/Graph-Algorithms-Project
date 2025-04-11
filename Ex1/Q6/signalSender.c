#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void send_signal(int pid, int bit){
    if (bit == 0){
        kill(pid, SIGUSR1);
    } else {
        kill(pid, SIGUSR2);
    }
}

int main(){
    int pid;
    int number;

    printf("Enter reciever PID: ");
    scanf("%d",&pid);

    printf("Enter message: ");
    scanf("%d", &number);


    for (int i = 7; i >= 0; i--){

        int bit = (number >> i) & 1;
        send_signal(pid, bit);
        usleep(100000);
    }
    return 0;
}