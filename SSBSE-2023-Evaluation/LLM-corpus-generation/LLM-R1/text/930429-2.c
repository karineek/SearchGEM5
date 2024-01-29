// Modification timestamp: 2023-08-14 13:33:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930429-2.c
int
f (b)
{
  return (b >> 1) > 0;
}

main ()
{
  if (!f (9))
    abort ();
  if (f (-9))
    abort ();
  exit (0);
}
