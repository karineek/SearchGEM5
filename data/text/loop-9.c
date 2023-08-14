// Modification timestamp: 2023-08-14 14:32:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-9.c
/* Source: Neil Booth, from PR # 115.  */

int false()
{
  return 0;
}

extern void abort (void);

int main (int argc,char *argv[])
{
  int count = 0;

  while (false() || count < -123)
    ++count;

  if (count)
    abort ();

  return 0;
}
