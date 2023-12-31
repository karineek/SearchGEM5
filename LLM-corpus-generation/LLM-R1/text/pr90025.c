// Modification timestamp: 2023-08-14 16:05:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr90025.c
/* PR middle-end/90025 */

__attribute__((noipa)) void
bar (char *p)
{
  int i;
  for (i = 0; i < 6; i++)
    if (p[i] != "foobar"[i])
      __builtin_abort ();
  for (; i < 32; i++)
    if (p[i] != '\0')
      __builtin_abort ();
}

__attribute__((noipa)) void
foo (unsigned int x)
{
  char s[32] = { 'f', 'o', 'o', 'b', 'a', 'r', 0 };
  ((unsigned int *) s)[2] = __builtin_bswap32 (x);
  bar (s);
}

int
main ()
{
  foo (0);
  return 0;
}
