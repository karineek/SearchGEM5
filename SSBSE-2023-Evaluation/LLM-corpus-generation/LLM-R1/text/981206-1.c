// Modification timestamp: 2023-08-14 13:51:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/981206-1.c
/* Verify unaligned address aliasing on Alpha EV[45].  */

static unsigned short x, y;

void foo()
{
  x = 0x345;
  y = 0x567;
}

int main()
{
  foo ();
  if (x != 0x345 || y != 0x567)
    abort ();
  exit (0);
}
