// Modification timestamp: 2023-08-14 12:51:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031216-1.c
/* PR optimization/13313 */
/* Origin: Mike Lerwill <mike@ml-solutions.co.uk> */

extern void abort(void);

void DisplayNumber (unsigned long v)
{
  if (v != 0x9aL)
    abort();
}

unsigned long ReadNumber (void)
{
  return 0x009a0000L;
}

int main (void)
{
  unsigned long tmp;
  tmp = (ReadNumber() & 0x00ff0000L) >> 16;
  DisplayNumber (tmp);
  return 0;
}
