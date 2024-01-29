// Modification Timestamp: 2023-08-03 23:00:00
// Original Source: https://www.programiz.com/c-programming/examples/leap-year

#include <stdio.h>

#define YEAR 2024

int main() {
    int year = YEAR;

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
