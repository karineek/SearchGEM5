// Modification timestamp: 2023-08-14 12:49:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031010-1.c

#include <stdio.h>
#include <stdlib.h>

long __attribute__((noinline))
foo (long ct, long cf, _Bool p1, _Bool p2, _Bool p3, int argc, char *argv[])
{
  if (argc != 7) {
    printf("Usage: %s <ct> <cf> <p1> <p2> <p3>\n", argv[0]);
    return 1;
  }

  ct = atol(argv[1]);
  cf = atol(argv[2]);
  p1 = atoi(argv[3]);
  p2 = atoi(argv[4]);
  p3 = atoi(argv[5]);

  long diff;

  diff = ct - cf;

  if (p1)
    {
      if (p2)
	{
	  if (p3)
	    {
	      long tmp = ct;
	      ct = cf;
	      cf = tmp;
	    }
	  diff = ct - cf;
	}

      return diff;
    }

  abort ();
}

int main (int argc, char *argv[])
{
  if (foo(2, 3, 1, 1, 1, argc, argv) == 0)
    abort ();
  return 0;
}
