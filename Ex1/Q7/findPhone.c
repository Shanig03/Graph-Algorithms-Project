#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>  // For file descriptor operations

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <Name or Part of Name>\n", argv[0]);
        return 1;
    }

    // Combine all name parts into one string
    char name[100] = "";
    for (int i = 1; i < argc; i++) {
        strcat(name, argv[i]);
        if (i < argc - 1)
            strcat(name, " ");
    }

    int pipe1[2], pipe2[2], pipe3[2];
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    // Child 1: grep
    pid_t pid1 = fork();
    if (pid1 == 0) {
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        execlp("grep", "grep", name, "phonebook.txt", NULL);
        perror("grep failed");
        exit(1);
    }

    // Child 2: sed (replace comma with space)
    pid_t pid2 = fork();
    if (pid2 == 0) {
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        execlp("sed", "sed", "s/,/ /", NULL);
        perror("sed failed");
        exit(1);
    }

    // Child 3: awk (get third field, which is the phone number)
    pid_t pid3 = fork();
    if (pid3 == 0) {
        dup2(pipe2[0], STDIN_FILENO);
        dup2(pipe3[1], STDOUT_FILENO);
        close(pipe1[0]); close(pipe1[1]);
        close(pipe2[0]); close(pipe2[1]);
        close(pipe3[0]); close(pipe3[1]);
        execlp("awk", "awk", "{print $3}", NULL);  // $3 = phone number
        perror("awk failed");
        exit(1);
    }

    // Parent: read and print result
    close(pipe1[0]); close(pipe1[1]);
    close(pipe2[0]); close(pipe2[1]);
    close(pipe3[1]); // parent reads from pipe3[0]

    char buffer[128];
    int found = 0;
    ssize_t bytesRead;

    while ((bytesRead = read(pipe3[0], buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0'; // null-terminate the string
        if (!found) {
            found = 1;
        }
        printf("%s", buffer);  // print the result
    }

    if (!found) {
        printf("No match found.\n");
    }

    close(pipe3[0]);

    // Wait for all children
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
