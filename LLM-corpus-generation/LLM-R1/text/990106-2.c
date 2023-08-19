// Modification timestamp: 2023-08-14 13:52:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990106-2.c
unsigned calc_mp(unsigned mod)
{
      unsigned a,b,c;
      c=-1;
      a=c/mod;
      b=0-a*mod;
      if (b > mod) { a += 1; b-=mod; }
      return b;
}

int main(int argc, char *argv[])
{
      unsigned x = 1234;
      unsigned y = calc_mp(x);

      if ((sizeof (y) == 4 && y != 680)
	  || (sizeof (y) == 2 && y != 134))
	abort ();
      exit (0);
}
