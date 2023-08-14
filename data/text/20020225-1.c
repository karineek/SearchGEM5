// Modification timestamp: 2023-08-14 12:10:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020225-1.c
/* This testcase failed at -O2 on powerpc64 due to andsi3 writing
   nonzero bits to the high 32 bits of a 64 bit register.  */

extern void abort (void);
extern void exit (int);

unsigned long foo (unsigned long base, unsigned int val)
{
  return base + (val & 0x80000001);
}

int main (void)
{
  if (foo (0L, 0x0ffffff0) != 0L)
    abort ();
  exit (0);
}
