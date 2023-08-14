// Modification timestamp: 2023-08-14 15:27:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr56982.c
/* { dg-require-effective-target indirect_jumps } */
#include <setjmp.h>

extern void abort (void);
extern void exit (int);

static jmp_buf env;

void baz (void)
{
  __asm__ volatile ("" : : : "memory");
}

static inline int g(int x)
{
    if (x)
    {
        baz();
        return 0;
    }
    else
    {
        baz();
        return 1;
    }
}

int f(int *e)
{
    if (*e)
      return 1;

    int x = setjmp(env);
    int n = g(x);
    if (n == 0)
      exit(0);
    if (x)
      abort();
    longjmp(env, 42);
}

int main(int argc, char** argv)
{
    int v = 0;
    return f(&v);
}
