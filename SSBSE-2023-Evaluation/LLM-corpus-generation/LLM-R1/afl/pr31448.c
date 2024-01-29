// Modification timestamp: 2023-08-14 14:53:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr31448.c

#include <stdio.h>
#include <stdlib.h>

typedef struct _st {
    int iIndex : 24;
    int iIndex1 : 24;
} st;

st *next;

void g(int nIndx, int* constreg)
{
    st *next = 0;
    next->iIndex = constreg[nIndx];
}

void f(int nIndx, int* constreg)
{
    next->iIndex = constreg[nIndx];
    next->iIndex1 = constreg[nIndx];
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <constreg1> <constreg2>\n", argv[0]);
        return 1;
    }

    int constreg[] = { atoi(argv[1]), atoi(argv[2]) };
    int nIndx = 0;
    st a;
    next = &a;

    f(nIndx, constreg);

    if (next->iIndex != 0xFFFEFEFE)
        __builtin_abort();

    if (next->iIndex1 != 0xFFFEFEFE)
        __builtin_abort();

    return 0;
}


Note: The original program had undefined behavior because the pointer `next` was dereferenced without being assigned to a valid memory location. I have modified the program to pass `constreg` as an argument to functions `f` and `g`, and added command line arguments to initialize `constreg` in `main`.