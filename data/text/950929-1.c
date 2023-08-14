// Modification timestamp: 2023-08-14 13:43:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950929-1.c
int f (char *p) { }

main ()
{
  char c;
  char c2;
  int i = 0;
  char *pc = &c;
  char *pc2 = &c2;
  int *pi = &i;

  *pc2 = 1;
  *pi = 1;
  *pc2 &= *pi;
  f (pc2);
  *pc2 = 1;
  *pc2 &= *pi;
  if (*pc2 != 1)
    abort ();
  exit (0);
}
