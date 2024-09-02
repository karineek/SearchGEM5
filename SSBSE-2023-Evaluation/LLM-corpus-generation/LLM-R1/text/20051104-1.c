// Modification timestamp: 2023-08-14 13:05:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051104-1.c
/* PR rtl-optimization/23567 */

struct
{
  int len;
  char *name;
} s;

int
main (void)
{
  s.len = 0;
  s.name = "";
  if (s.name [s.len] != 0)
    s.name [s.len] = 0;
  return 0;
}
