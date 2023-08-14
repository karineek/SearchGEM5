// Modification timestamp: 2023-08-14 15:02:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38151.c

#include <stdio.h>
#include <stdlib.h>

void abort (void);

struct S2848
{
  unsigned int a;
  _Complex int b;
  struct
  {
  } __attribute__ ((aligned)) c;
};

struct S2848 s2848;

int fails;

void  __attribute__((noinline))
check2848va (int z, ...)
{
  struct S2848 arg;
  __builtin_va_list ap;

  __builtin_va_start (ap, z);

  arg = __builtin_va_arg (ap, struct S2848);

  if (s2848.a != arg.a)
    ++fails;
  if (s2848.b != arg.b)
    ++fails;

  __builtin_va_end (ap);
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s2848.a = atoi(argv[1]);
  s2848.b = (723419448 + -218144346 * __extension__ 1i);

  check2848va (1, s2848);

  if (fails)
    abort ();

  return 0;
}
