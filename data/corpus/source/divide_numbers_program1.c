// Modification Timestamp: 2023-08-03 21:45:00
// Original Source: LLM generated

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[2]);
    double result = num1 / num2;

    printf("Division Result = %.2lf", result);
    return 0;
}
