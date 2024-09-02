// Modification timestamp: 2023-08-14 12:06:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011109-2.c
int main(void)
{
  char *c1 = "foo";
  char *c2 = "foo";
  int i;
  for (i = 0; i < 3; i++)
    if (c1[i] != c2[i])
      abort ();
  exit (0);
}
