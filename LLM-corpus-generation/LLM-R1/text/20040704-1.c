// Modification timestamp: 2023-08-14 12:56:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040704-1.c
/* PR 16348: Make sure that condition-first false loops DTRT.  */

extern void abort ();

int main()
{
  for (; 0 ;)
    {
      abort ();
    label:
      return 0;
    }
  goto label;
}
