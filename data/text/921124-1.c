// Modification timestamp: 2023-08-14 13:31:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921124-1.c
f(x, d1, d2, d3)
   double d1, d2, d3;
{
   return x;
}

g(b,s,x,y,i,j)
     char *b,*s;
     double x,y;
{
  if (x != 1.0 || y != 2.0 || i != 3 || j != 4)
    abort();
}

main()
{
  g("","", 1.0, 2.0, f(3, 0.0, 0.0, 0.0), f(4, 0.0, 0.0, 0.0));
  exit(0);
}
