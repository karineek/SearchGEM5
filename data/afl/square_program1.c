// Modification Timestamp: 2023-08-03 21:30:00
// Original Source: LLM generated

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <num>\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);
    int square = num * num;

    printf("Square of %d = %d", num, square);
    return 0;
}
