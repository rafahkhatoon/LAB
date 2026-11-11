
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};

    execvp("ls", args);

    printf("Exec failed\n");

    return 0;
}
