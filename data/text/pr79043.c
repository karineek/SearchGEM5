// Modification timestamp: 2023-08-14 15:53:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79043.c
/* PR ipa/78791 */

int val;

int *ptr = &val;
float *ptr2 = &val;

static
__attribute__((always_inline, optimize ("-fno-strict-aliasing")))
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
