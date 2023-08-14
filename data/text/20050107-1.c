// Modification timestamp: 2023-08-14 13:01:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050107-1.c
typedef enum { C = 1, D = 2 } B;
extern void abort (void);

struct S
{
  B __attribute__ ((mode (byte))) a;
  B __attribute__ ((mode (byte))) b;
};

void
foo (struct S *x)
{
  if (x->a != C || x->b != D)
    abort ();
}

int
main (void)
{
  struct S s;
  s.a = C;
  s.b = D;
  foo (&s);
  return 0;
}
