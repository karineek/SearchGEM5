// Modification timestamp: 2023-08-14 13:48:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961223-1.c
/* { dg-options "-fgnu89-inline" } */

extern void exit (int);
extern void abort (void);

struct s {
  double d;
};

inline struct s
sub (struct s s)
{
  s.d += 1.0;
  return s;
}

int
main ()
{
  struct s t = { 2.0 };
  t = sub (t);
  if (t.d != 3.0)
    abort ();
  exit (0);
}
