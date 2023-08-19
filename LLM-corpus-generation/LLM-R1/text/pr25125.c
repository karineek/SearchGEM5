// Modification timestamp: 2023-08-14 14:49:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr25125.c
extern void exit (int);
extern void abort (void);
extern unsigned short f (short a) __attribute__((__noinline__));

unsigned short
f (short a)
{
  short b;

  if (a > 0)
    return 0;
  b = ((int) a) + - (int) 32768;
  return b;
}

int
main (void)
{
  if (sizeof (short) < 2
      || sizeof (short) >= sizeof (int))
    exit (0);

  if (f (-32767) != 1)
    abort ();

  exit (0);
}
