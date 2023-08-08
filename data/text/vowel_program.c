// Modification Timestamp: 2023-08-03 22:45:00
// Original Source: https://www.programiz.com/c-programming/examples/vowel-consonant

#include <stdio.h>

#define CHAR 'e'

int main() {
    char ch = CHAR;

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        printf("%c is a vowel", ch);
    else
        printf("%c is a consonant", ch);

    return 0;
}
