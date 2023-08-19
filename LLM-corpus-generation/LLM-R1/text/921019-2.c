// Modification timestamp: 2023-08-14 13:30:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921019-2.c
main()
{
  double x,y=0.5;
  x=y/0.2;
  if(x!=x)
    abort();
  exit(0);
}
