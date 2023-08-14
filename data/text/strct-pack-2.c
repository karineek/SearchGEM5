// Modification timestamp: 2023-08-14 16:14:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strct-pack-2.c
typedef struct
{
  short a __attribute__ ((aligned (2),packed));
  short *ap[2]  __attribute__ ((aligned (2),packed));
} A;

main ()
{
  short i, j = 1;
  A a, *ap = &a;
  ap->ap[j] = &i;
  exit (0);
}
