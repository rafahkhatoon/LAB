
#include <unistd.h>

int main() {
    char str[50];
    int n;

    write(1, "Enter text: ", 12);
    n = read(0, str, 50);

    write(1, "You entered: ", 13);
    write(1, str, n);

    return 0;
}
