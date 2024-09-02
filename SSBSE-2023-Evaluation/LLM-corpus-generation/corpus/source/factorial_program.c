// Modification Timestamp: 2023-08-03 23:15:00
// Original Source: https://www.programiz.com/c-programming/examples/factorial.c

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num>\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);
    int factorial = 1;

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    printf("Factorial of %d = %d", num, factorial);
    return 0;
}
