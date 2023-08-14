// Modification timestamp: 2023-08-14 14:47:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22348.c
void abort (void);
void f(int i)
{
  if (i>4 + 3 * 16)
    abort();
}

int main()
{
  unsigned int buflen, i;
  buflen = 4 + 3 * 16;
  for (i = 4; i < buflen; i+= 3)
    f(i);
  return 0;
}
