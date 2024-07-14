#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        printf("Child process\n");
        exit(0);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
        printf("Parent process\n");
    } else {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    return 0;
}
