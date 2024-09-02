// Modification Timestamp: 2023-08-03 19:30:00
// Original Source: https://www.programiz.com/c-programming/examples/product-numbers.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double a, b, product;

    if (argc != 3) {
        printf("Usage: %s <number1> <number2>\n", argv[0]);
        return 1;
    }

    a = atof(argv[1]);
    b = atof(argv[2]);

    // Calculating product
    product = a * b;

    // %.2lf displays number up to 2 decimal points
    printf("Product = %.2lf", product);

    return 0;
}
