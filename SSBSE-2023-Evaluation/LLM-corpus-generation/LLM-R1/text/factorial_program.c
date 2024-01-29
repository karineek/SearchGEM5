// Modification Timestamp: 2023-08-03 23:15:00
// Original Source: https://www.programiz.com/c-programming/examples/factorial

#include <stdio.h>

#define NUM 5

int main() {
    int num = NUM;
    int factorial = 1;

    for (int i = 1; i <= num; i++) {
        factorial *= i;
    }

    printf("Factorial of %d = %d", num, factorial);
    return 0;
}
