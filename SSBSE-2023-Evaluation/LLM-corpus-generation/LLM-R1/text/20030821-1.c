// Modification timestamp: 2023-08-14 12:47:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030821-1.c
extern void abort (void);

int
foo (int x)
{
  if ((int) (x & 0x80ffffff) != (int) (0x8000fffe))
    abort ();

  return 0;
}

int
main ()
{
  return foo (0x8000fffe);
}
