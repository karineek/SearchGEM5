// Modification timestamp: 2023-08-14 11:57:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010123-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();
extern void exit(int);

struct s
{
    int value;
    char *string;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    int i;
    for (i = 0; i < 4; i++)
    {
        struct s *t = &(struct s) { atoi(argv[1]), "hey there" };
        if (t->value != atoi(argv[1]))
            abort();
        t->value = atoi(argv[2]);
        if (t->value != atoi(argv[2]))
            abort();
    }
    exit(0);
}
