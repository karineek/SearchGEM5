// Modification timestamp: 2023-08-14 14:44:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr19689.c
/* { dg-require-effective-target int32plus } */
extern void abort (void);

struct
{
  int b : 29;
} f;

void foo (short j)
{
  f.b = j;
}

int main()
{
  foo (-55);
  if (f.b != -55)
    abort ();
  return 0;
}
