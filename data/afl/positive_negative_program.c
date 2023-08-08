// Modification Timestamp: 2023-08-03 22:30:00
// Original Source: https://www.programiz.com/c-programming/examples/positive-negative

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num>\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);

    if (num > 0)
        printf("%d is positive", num);
    else if (num < 0)
        printf("%d is negative", num);
    else
        printf("You entered zero");

    return 0;
}
