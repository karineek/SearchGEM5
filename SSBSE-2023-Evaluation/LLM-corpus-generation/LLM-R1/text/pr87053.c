// Modification timestamp: 2023-08-14 16:02:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr87053.c
/* PR middle-end/87053 */

const union
{ struct {
    char x[4];
    char y[4];
  };
  struct {
    char z[8];
  };
} u = {{"1234", "567"}};

int main ()
{
  if (__builtin_strlen (u.z) != 7)
    __builtin_abort ();
}
