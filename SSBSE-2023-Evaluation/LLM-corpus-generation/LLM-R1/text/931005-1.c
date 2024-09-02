// Modification timestamp: 2023-08-14 13:39:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931005-1.c
typedef struct
{
  char x;
} T;

T
f (s1)
     T s1;
{
  T s1a;
  s1a.x = s1.x;
  return s1a;
}

main ()
{
  T s1a, s1b;
  s1a.x = 100;
  s1b = f (s1a);
  if (s1b.x != 100)
    abort ();
  exit (0);
}
