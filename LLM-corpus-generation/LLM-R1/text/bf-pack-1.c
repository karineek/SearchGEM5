// Modification timestamp: 2023-08-14 14:05:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bf-pack-1.c
struct foo
{
  unsigned half:16;
  unsigned long whole:32 __attribute__ ((packed));
};

f (struct foo *q)
{
  if (q->half != 0x1234)
    abort ();
  if (q->whole != 0x56789abcL)
    abort ();
}

main ()
{
  struct foo bar;

  bar.half = 0x1234;
  bar.whole = 0x56789abcL;
  f (&bar);
  exit (0);
}
