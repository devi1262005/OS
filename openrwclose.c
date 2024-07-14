#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char buffer[] = "Hello, this is a file system call example.";
    write(fd, buffer, sizeof(buffer));

    close(fd);
    return 0;
}
