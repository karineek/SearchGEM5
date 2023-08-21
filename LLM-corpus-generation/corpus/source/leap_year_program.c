// Modification Timestamp: 2023-08-03 23:00:00
// Original Source: https://www.programiz.com/c-programming/examples/leap-year.c

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <year>\n", argv[0]);
        return 1;
    }

    int year = atoi(argv[1]);

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                printf("%d is a leap year", year);
            else
                printf("%d is not a leap year", year);
        } else
            printf("%d is a leap year", year);
    } else
        printf("%d is not a leap year", year);

    return 0;
}
