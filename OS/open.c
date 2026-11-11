
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    fd = open("test.txt", O_RDONLY);

    if(fd == -1) {
        printf("File opening failed\n");
    }
    else {
        printf("File opened successfully\n");
        printf("File descriptor = %d\n", fd);
        close(fd);
    }

    return 0;
}
