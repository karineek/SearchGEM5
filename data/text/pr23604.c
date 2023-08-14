// Modification timestamp: 2023-08-14 14:48:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr23604.c
extern void abort (void);

int g(int i, int j)
{
  if (i>-1)
    if (i<2)
     {
        if (i != j)
          {
            if (j != 0)
                return 0;
          }
     }
  return 1;
}

int main(void)
{
  if (!g(1, 0))
   abort ();
  return 0;
}
