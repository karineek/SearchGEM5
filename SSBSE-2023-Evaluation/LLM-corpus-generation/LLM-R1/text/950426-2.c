// Modification timestamp: 2023-08-14 13:41:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950426-2.c
main()
{
  long int i = -2147483647L - 1L; /* 0x80000000 */
  char ca = 1;

  if (i >> ca != -1073741824L)
    abort ();

  if (i >> i / -2000000000L != -1073741824L)
    abort ();

  exit (0);
}
