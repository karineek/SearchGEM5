// Modification timestamp: 2023-08-14 12:41:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021219-1.c
/* PR optimization/8988 */
/* Contributed by Kevin Easton */

void foo(char *p1, char **p2)
{}

int main(void)
{
  char str[] = "foo { xx }";
  char *ptr = str + 5;

  foo(ptr, &ptr);

  while (*ptr && (*ptr == 13 || *ptr == 32))
    ptr++;

  return 0;
}
