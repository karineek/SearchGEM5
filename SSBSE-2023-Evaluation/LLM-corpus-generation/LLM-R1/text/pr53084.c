// Modification timestamp: 2023-08-14 15:22:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr53084.c
/* PR middle-end/53084 */

extern void abort (void);

__attribute__((noinline, noclone)) void
bar (const char *p)
{
  if (p[0] != 'o' || p[1] != 'o' || p[2])
    abort ();
}

int
main ()
{
  static const char *const foo[] = {"foo" + 1};
  bar (foo[0]);
  return 0;
}
