// Modification Timestamp: 2023-08-03 22:30:00
// Original Source: https://www.programiz.com/c-programming/examples/positive-negative

#include <stdio.h>

#define NUM 0

int main() {
    int num = NUM;

    if (num > 0)
        printf("%d is positive", num);
    else if (num < 0)
        printf("%d is negative", num);
    else
        printf("You entered zero");

    return 0;
}
