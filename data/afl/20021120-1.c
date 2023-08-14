// Modification timestamp: 2023-08-14 12:38:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021120-1.c

#include <stdio.h>
#include <stdlib.h>

#define OP1(L, N, R, I, J) L N##I##J R
#define OP2(L, N, R, I) \
    OP1(L, N, R, 0, I), OP1(L, N, R, 1, I), \
    OP1(L, N, R, 2, I), OP1(L, N, R, 3, I)
#define OP(L, N, R) \
    OP2(L, N, R, 0), OP2(L, N, R, 1), OP2(L, N, R, 2), OP2(L, N, R, 3), \
    OP2(L, N, R, 4), OP2(L, N, R, 5), OP2(L, N, R, 6), OP2(L, N, R, 7)

#define DECLARE(N) OP (, N,)

#define COPYIN(N, ADDR) OP (, N, = *(ADDR++))

#define COPYOUT(N, ADDR) OP (*(ADDR++) =, N,)

#define ADD(N, ADDR) OP (, N, += *(ADDR++))

volatile double gd[32];
volatile float gf[32];

void foo (int n, double *gd, float *gf)
{
  double DECLARE(d);
  float DECLARE(f);
  volatile double *pd;
  volatile float *pf;
  int i;

  pd = gd; COPYIN (d, pd);
  for (i = 0; i < n; i++)
    {
      pf = gf; COPYIN (f, pf);
      pd = gd; ADD (d, pd);
      pd = gd; ADD (d, pd);
      pd = gd; ADD (d, pd);
      pf = gf; COPYOUT (f, pf);
    }
  pd = gd; COPYOUT (d, pd);
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  double gd[32];
  float gf[32];

  for (i = 0; i < 32; i++)
    gd[i] = i, gf[i] = i;
  foo (atoi(argv[1]), gd, gf);
  for (i = 0; i < 32; i++)
    if (gd[i] != i * 4 || gf[i] != i)
      abort ();
  exit (0);
}
