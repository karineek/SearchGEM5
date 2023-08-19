// Modification timestamp: 2023-08-14 12:06:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011114-1.c
char foo(char bar[])
{
  return bar[1];
}
extern char foo(char *);
int main(void)
{
  if (foo("xy") != 'y')
    abort ();
  exit (0);
}
