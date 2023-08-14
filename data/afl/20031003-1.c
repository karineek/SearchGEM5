// Modification timestamp: 2023-08-14 12:49:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031003-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void abort (void);

int f1(int arg1)
{
  return (int)arg1;
}

int f2(int arg1)
{
  return (int)(float)arg1;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);

#if INT_MAX == 2147483647
  if (f1(arg1) != arg2)
    abort ();

#ifdef __SPU__
  /* SPU float rounds towards zero.  */
  if (f2(arg1) != 0x7fffff80)
    abort ();
#else
  if (f2(arg1) != arg2)
    abort ();
#endif
#endif
  return 0;
}
