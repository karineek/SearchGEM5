// Modification timestamp: 2023-08-14 13:07:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20061101-1.c
/* PR rtl-optimization/28970 */
/* Origin: Peter Bergner <bergner@vnet.ibm.com> */
/* { dg-require-effective-target int32plus } */

extern void abort (void);

int tar (int i)
{
  if (i != 36863)
    abort ();

  return -1;
}

void bug(int q, int bcount)
{
  int j = 0;
  int outgo = 0;

  while(j != -1)
    {
      outgo++;
      if (outgo > q-1)
        outgo = q-1;
      j = tar (outgo*bcount);
    }
}

int main(void)
{
  bug(5, 36863);
  return 0;
}
