// Modification timestamp: 2023-08-14 13:01:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050106-1.c
/* PR tree-optimization/19283 */

void abort (void);

static inline unsigned short
foo (unsigned int *p)
{
  return *p;
};

unsigned int u;

int
main ()
{
  if ((foo (&u) & 0x8000) != 0)
    abort ();
  return 0;
}
