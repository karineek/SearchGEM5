// Modification timestamp: 2023-08-14 17:04:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/widechar-1.c
#define C L'\400'

#if C
#define zero (!C)
#else
#define zero C
#endif

main()
{
  if (zero != 0)
    abort ();
  exit (0);
}
