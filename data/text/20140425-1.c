// Modification timestamp: 2023-08-14 13:21:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140425-1.c
/* PR target/60941 */
/* Reported by Martin Husemann <martin@netbsd.org> */

extern void abort (void);

static void __attribute__((noinline))
set (unsigned long *l)
{
  *l = 31;
}

int main (void)
{
  unsigned long l;
  int i;

  set (&l);
  i = (int) l;
  l = (unsigned long)(2U << i);
  if (l != 0)
    abort ();
  return 0;
}
