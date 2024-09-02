// Modification timestamp: 2023-08-14 16:57:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-18.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef double L;
void f (L p0, L p1, L p2, L p3, L p4, L p5, L p6, L p7, L p8, ...)
{
  va_list select;

  va_start (select, p8);

  if (va_arg (select, int) != 10)
    abort ();
  if (va_arg (select, int) != 11)
    abort ();
  if (va_arg (select, int) != 12)
    abort ();

  va_end (select);
}

int main (int argc, char *argv[])
{
  if (argc != 15) {
    printf("Usage: %s <p0> <p1> <p2> <p3> <p4> <p5> <p6> <p7> <p8> <p9> <p10> <p11> <p12> <p13> <p14>\n", argv[0]);
    return 1;
  }

  L p0 = atof(argv[1]);
  L p1 = atof(argv[2]);
  L p2 = atof(argv[3]);
  L p3 = atof(argv[4]);
  L p4 = atof(argv[5]);
  L p5 = atof(argv[6]);
  L p6 = atof(argv[7]);
  L p7 = atof(argv[8]);
  L p8 = atof(argv[9]);
  
  f(p0, p1, p2, p3, p4, p5, p6, p7, p8, atoi(argv[10]), atoi(argv[11]), atoi(argv[12]));

  exit (0);
}
