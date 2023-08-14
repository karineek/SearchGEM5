// Modification timestamp: 2023-08-14 13:58:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991221-1.c
int main( void )
{
   unsigned long totalsize = 80;
   unsigned long msize = 64;

   if (sizeof(long) != 4)
     exit(0);

   if ( totalsize > (2147483647L   * 2UL + 1)
        || (msize != 0 && ((msize - 1) > (2147483647L   * 2UL + 1) )))
      abort();
   exit( 0 );
}
