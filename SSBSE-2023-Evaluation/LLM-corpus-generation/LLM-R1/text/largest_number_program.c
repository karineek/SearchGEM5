// Modification Timestamp: 2023-08-03 22:15:00
// Original Source: https://www.programiz.com/c-programming/examples/largest-number

#include <stdio.h>

#define NUM1 45
#define NUM2 87
#define NUM3 23

int main() {
    int num1 = NUM1;
    int num2 = NUM2;
    int num3 = NUM3;
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
