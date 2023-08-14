// Modification timestamp: 2023-08-14 14:08:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/built-in-setjmp.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

jmp_buf buf;

extern int strcmp(const char *, const char *);
extern char *strcpy(char *, const char *);
extern void abort(void);
extern void exit(int);

void sub2(void) {
    longjmp(buf, 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    char *p = (char *)malloc(20 * sizeof(char));

    strcpy(p, "test");

    if (setjmp(buf) != 0) {
        if (strcmp(p, "test") != 0)
            abort();

        exit(0);
    }

    {
        int *q = (int *)malloc((p[2] * sizeof(int)));
        int i;

        for (i = 0; i < p[2]; i++)
            q[i] = 0;

        while (1)
            sub2();
    }
}
