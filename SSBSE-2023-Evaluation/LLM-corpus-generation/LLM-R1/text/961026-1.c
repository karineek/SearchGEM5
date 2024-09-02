// Modification timestamp: 2023-08-14 13:47:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961026-1.c
int
test (arg)
     int arg;
{
  if (arg > 0 || arg == 0)
    return 0;
  return -1;
}

main ()
{
  if (test (0) != 0)
    abort ();
  if (test (-1) != -1)
    abort ();
  exit (0);
}
