// Modification timestamp: 2023-08-14 13:58:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/alias-1.c
int val;

int *ptr = &val;
float *ptr2 = &val;

__attribute__((optimize ("-fno-strict-aliasing")))
typepun ()
{
  *ptr2=0;
}

main()
{
  *ptr=1;
  typepun ();
  if (*ptr)
    __builtin_abort ();
}
