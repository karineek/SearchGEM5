// Modification Timestamp: 2023-08-03 22:15:00
// Original Source: https://www.programiz.com/c-programming/examples/largest-number.c

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <num1> <num2> <num3>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int num3 = atoi(argv[3]);
    int largest;

    if (num1 >= num2 && num1 >= num3)
        largest = num1;
    else if (num2 >= num1 && num2 >= num3)
        largest = num2;
    else
        largest = num3;

    printf("Largest number = %d", largest);
    return 0;
}
