// Modification timestamp: 2023-08-14 13:08:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070201-1.c
/* PR middle-end/30473 */

extern int sprintf (char *, const char *, ...);
extern void abort (void);

char *
foo (char *buf, char *p)
{
  sprintf (buf, "abcde", p++);
  return p;
}

int
main (void)
{
  char buf[6];
  if (foo (buf, &buf[2]) != &buf[3])
    abort ();
  return 0;
}
