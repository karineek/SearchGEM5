// Modification Timestamp: 2023-08-03 22:45:00
// Original Source: https://www.programiz.com/c-programming/examples/vowel-consonant.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2 || strlen(argv[1]) != 1) {
        printf("Usage: %s <character>\n", argv[0]);
        return 1;
    }

    char ch = argv[1][0];

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        printf("%c is a vowel", ch);
    else
        printf("%c is a consonant", ch);

    return 0;
}
