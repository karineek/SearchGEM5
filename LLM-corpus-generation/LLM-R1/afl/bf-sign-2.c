// Modification timestamp: 2023-08-14 14:05:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/bf-sign-2.c

#include <stdio.h>
#include <stdlib.h>

struct X {
  unsigned int     u3:3;
    signed long int  s31:31;
    signed long int  s32:32;
  unsigned long int  u31:31;
  unsigned long int  u32:32;
  unsigned long long ull3 :3;
  unsigned long long ull35:35;
  unsigned u15:15;
};

struct X x;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int value = atoi(argv[1]);

  if ((x.u3 - value) >= 0)		
    abort ();

  if ((x.s31 - value) >= 0)		
    abort ();

  if ((x.s32 - value) >= 0)		
    abort ();

  if ((x.u15 - value) >= 0)		
    abort ();

  if (sizeof (int) >= 4)
  {
    if ((x.u31 - value) >= 0)	
      abort ();
  }
  else
  {
    if ((x.u31 - value) < 0)	
      abort ();
  }

  if ((x.u32 - value) < 0)		
    abort ();

  if ((x.ull3 - value) >= 0)	
    abort ();

  if ((x.ull35 - value) < 0)	
    abort ();

  exit (0);
}


Note that in this case, I assume that the value provided as a command line argument is used to subtract from the bitfields in the `struct X`. You can adjust the code accordingly if that's not the case.