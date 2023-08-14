// Modification timestamp: 2023-08-14 15:59:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr84339.c
/* PR tree-optimization/84339 */

struct S { int a; char b[1]; };

__attribute__((noipa)) int
foo (struct S *p)
{
  return __builtin_strlen (&p->b[0]);
}

__attribute__((noipa)) int
bar (struct S *p)
{
  return __builtin_strlen (p->b);
}

int
main ()
{
  struct S *p = __builtin_malloc (sizeof (struct S) + 16);
  if (p)
    {
      p->a = 1;
      __builtin_strcpy (p->b, "abcdefg");
      if (foo (p) != 7 || bar (p) != 7)
	__builtin_abort ();
      __builtin_free (p);
    }
  return 0;
}
