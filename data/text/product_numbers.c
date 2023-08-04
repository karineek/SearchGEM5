// Modification Timestamp: 2023-08-03 19:30:00
// Original Source: https://www.programiz.com/c-programming/examples/product-numbers

#include <stdio.h>

int main() {
    double a, b, product;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);  

    // Calculating product
    product = a * b;

    // %.2lf displays number up to 2 decimal points
    printf("Product = %.2lf", product);

    return 0;
}
