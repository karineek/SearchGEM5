// Modification timestamp: 2023-08-14 13:49:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980526-3.c
int compare(x, y)
unsigned int x;
unsigned int y;
{
   if (x==y)
     return 0;
   else
     return 1;
}

main()
{
 unsigned int i, j, k, l;
 i = 5; j = 2; k=0; l=2;
 if (compare(5%(~(unsigned) 2), i%~j)
     || compare(0, k%~l))
    abort();
 else
    exit(0);
}
