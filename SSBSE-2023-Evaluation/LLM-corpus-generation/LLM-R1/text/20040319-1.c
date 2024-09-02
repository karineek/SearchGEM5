// Modification timestamp: 2023-08-14 12:52:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040319-1.c
int
blah (int zzz)
{
  int foo;
  if (zzz >= 0)
    return 1;
  foo = (zzz >= 0 ? (zzz) : -(zzz));
  return foo;
}

main()
{
  if (blah (-1) != 1)
    abort ();
  else
    exit (0);
}
