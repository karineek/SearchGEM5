// Modification timestamp: 2023-08-14 13:50:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980617-1.c
void foo (unsigned int * p)
{
  if ((signed char)(*p & 0xFF) == 17 || (signed char)(*p & 0xFF) == 18)
    return;
  else
    abort ();
}

int main ()
{
  int i = 0x30011;
  foo(&i);
  exit (0);
}
