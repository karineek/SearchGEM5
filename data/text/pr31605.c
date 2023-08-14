// Modification timestamp: 2023-08-14 14:54:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr31605.c
void put_field (unsigned int start, unsigned int len)
{
  int cur_bitshift = ((start + len) % 8) - 8;
  if (cur_bitshift > -8)
    exit (0);
}

int
main ()
{
  put_field (0, 1);
  abort ();
}
