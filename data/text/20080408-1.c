// Modification timestamp: 2023-08-14 13:13:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20080408-1.c
extern void abort (void);
int main ()
{
  short ssi = 126;
  unsigned short usi = 65280;
  int fail = !(ssi < usi);
  if (fail)
    abort ();
  return 0;
}
