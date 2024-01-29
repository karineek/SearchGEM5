// Modification timestamp: 2023-08-14 14:52:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr29797-2.c
extern void abort(void);

unsigned long bar(void) { return 32768; }

int main()
{
  unsigned long nStyle = bar ();
  if (nStyle & 32768)
    nStyle |= 65536;
  if (nStyle != (32768 | 65536))
    abort ();
  return 0;
}
