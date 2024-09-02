// Modification Timestamp: 2023-08-03 18:00:30
// Original Source: https://www.programiz.com/c-programming/examples/add-numbers.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int number1, number2, sum;

    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    number1 = atoi(argv[1]);
    number2 = atoi(argv[2]);

    // calculate the sum
    sum = number1 + number2;

    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}
