
#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat s;

    stat("test.txt", &s);

    printf("File size = %ld bytes\n", s.st_size);
    printf("File permissions = %o\n", s.st_mode);

    return 0;
}
