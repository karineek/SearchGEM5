// Modification Timestamp: 2023-08-03 22:00:00
// Original Source: LLM generated

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int difference = num1 - num2;

    printf("Difference = %d", difference);
    return 0;
}
