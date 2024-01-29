// Modification timestamp: 2023-08-14 12:06:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011121-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s
{
    int i[18];
    char f;
    char b[2];
};

struct s s1;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    struct s s2;
    s2.b[0] = atoi(argv[1]);
    memcpy(&s2, &s1, sizeof(struct s) - sizeof(int) * 16);
    if (s2.b[0] != atoi(argv[1]))
        abort();
    exit(0);
}
