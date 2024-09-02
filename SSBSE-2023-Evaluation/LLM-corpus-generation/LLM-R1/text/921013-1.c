// Modification timestamp: 2023-08-14 13:30:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921013-1.c
f(d,x,y,n)
int*d;
float*x,*y;
int n;
{
  while(n--){*d++=*x++==*y++;}
}

main()
{
  int r[4];
  float a[]={5,1,3,5};
  float b[]={2,4,3,0};
  int i;
  f(r,a,b,4);
  for(i=0;i<4;i++)
    if((a[i]==b[i])!=r[i])
      abort();
  exit(0);
}
