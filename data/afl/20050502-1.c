// Modification timestamp: 2023-08-14 13:03:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050502-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);
extern int strcmp(const char *, const char *);

int bar(const char **x)
{
    return *(*x)++;
}

int baz(int c)
{
    return c != '@';
}

void foo(const char **w, char *x, _Bool y, _Bool z)
{
    char c = bar(w);
    int i = 0;

    while (1)
    {
        x[i++] = c;
        c = bar(w);
        if (y && c == '\'')
            break;
        if (z && c == '\"')
            break;
        if (!y && !z && !baz(c))
            break;
    }
    x[i] = 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
  
    char buf[64];
    const char *p;
    p = argv[1];
    foo(&p, buf, 1, 0);
    if (strcmp(p, "fgh") != 0 || strcmp(buf, "abcde") != 0)
        abort();
    p = argv[1];
    foo(&p, buf, 0, 1);
    if (strcmp(p, "HI") != 0 || strcmp(buf, "ABCDEFG") != 0)
        abort();
    p = argv[1];
    foo(&p, buf, 1, 1);
    if (strcmp(p, "e'fgh") != 0 || strcmp(buf, "abcd") != 0)
        abort();
    p = argv[1];
    foo(&p, buf, 1, 1);
    if (strcmp(p, "G\"HI") != 0 || strcmp(buf, "ABCDEF") != 0)
        abort();
    p = argv[1];
    foo(&p, buf, 0, 0);
    if (strcmp(p, "gh") != 0 || strcmp(buf, "abcdef") != 0)
        abort();
    return 0;
}

