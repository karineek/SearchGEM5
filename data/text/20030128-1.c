// Modification timestamp: 2023-08-14 12:42:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030128-1.c
unsigned char x = 50;
volatile short y = -5;

int main ()
{
  x /= y;
  if (x != (unsigned char) -10)
    abort ();
  exit (0);
}
