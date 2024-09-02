// Modification timestamp: 2023-08-14 14:26:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ffs-1.c
__volatile int a = 0;

extern void abort (void);
extern void exit (int);

int
main (void)
{
  if (__builtin_ffs (a) != 0)
    abort ();
  exit (0);
}
