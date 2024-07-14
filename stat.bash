#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;
    if (stat("example.txt", &st) == 0) {
        printf("Size of file: %ld bytes\n", st.st_size);
    } else {
        perror("Error getting file information");
        return 1;
    }

    return 0;
}
