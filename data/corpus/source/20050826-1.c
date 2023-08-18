// Modification timestamp: 2023-08-14 13:04:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050826-1.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct A
{
  char a1[1];
  char a2[5];
  char a3[1];
  char a4[2048 - 7];
} a;

typedef __SIZE_TYPE__ size_t;
extern void *memset (void *, int, size_t);
extern void *memcpy (void *, const void *, size_t);
extern int memcmp (const void *, const void *, size_t);
extern void abort (void);

void bar(struct A *x, const char* arg1, const char* arg2, const char* arg3, int arg4) {
    size_t i;
    if (memcmp(x, arg1, arg4))
        abort();
    for (i = 0; i < sizeof(x->a4); i++)
        if (x->a4[i])
            abort();
}

int foo(const char* arg1, int arg2, const char* arg3, int arg4, const char* arg5) {
    memset(&a, 0, sizeof(a));
    a.a1[0] = arg2;
    memcpy(a.a2, arg3, sizeof(arg3));
    a.a3[0] = arg2;
    bar(&a, arg1, arg3, arg5, sizeof(arg5));
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5>\n", argv[0]);
        return 1;
    }

    const char* arg1 = argv[1];
    int arg2 = atoi(argv[2]);
    const char* arg3 = argv[3];
    int arg4 = atoi(argv[4]);
    const char* arg5 = argv[5];

    foo(arg1, arg2, arg3, arg4, arg5);
    return 0;
}
