// Modification timestamp: 2023-08-14 14:48:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr23467.c
/* { dg-skip-if "small alignment" { pdp11-*-* } } */

struct s1
{
  int __attribute__ ((aligned (8))) a;
};

struct
{
  char c;
  struct s1 m;
} v;

int
main (void)
{
  if ((int)&v.m & 7)
    abort ();
  exit (0);
}
