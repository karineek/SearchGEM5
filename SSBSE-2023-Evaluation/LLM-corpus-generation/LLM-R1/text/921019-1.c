// Modification timestamp: 2023-08-14 13:30:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921019-1.c
void *foo[]={(void *)&("X"[0])};

main ()
{
  if (((char*)foo[0])[0] != 'X')
    abort ();
  exit (0);
}
