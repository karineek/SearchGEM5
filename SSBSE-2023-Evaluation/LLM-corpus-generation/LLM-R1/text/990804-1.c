// Modification timestamp: 2023-08-14 13:55:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990804-1.c
int gfbyte ( void )
{
 return 0;
}

int main( void )
{
 int i,j,k ;

 i = gfbyte();

 i = i + 1 ;

 if ( i == 0 )
     k = -0 ;
 else
     k = i + 0 ;

 if (i != 1)
   abort ();

 k = 1 ;
 if ( k <= i)
     do
	 j = gfbyte () ;
     while ( k++ < i ) ;

 exit (0);
}
