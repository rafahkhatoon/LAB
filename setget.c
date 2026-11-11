
#include <stdio.h>
#include <stdlib.h>

int main() {
    setenv("NAME", "Rafah", 1);

    printf("Name = %s\n", getenv("NAME"));

    return 0;
}
