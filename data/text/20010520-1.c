// Modification timestamp: 2023-08-14 11:59:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010520-1.c
static unsigned int expr_hash_table_size = 1;

int
main ()
{
  int del = 1;
  unsigned int i = 0;

  if (i < expr_hash_table_size && del)
    exit (0);
  abort ();
}
