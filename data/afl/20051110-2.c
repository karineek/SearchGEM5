// Modification timestamp: 2023-08-14 13:05:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20051110-2.c

#include <stdio.h>
#include <stdlib.h>

void add_unwind_adjustsp (long);
void abort (void);

unsigned char bytes[5];

int flag;

void add_unwind_adjustsp (long offset)
{
  int n;
  unsigned long o;

  o = (long) ((offset - atoi(argv[1])) >> 2);

  n = 0;
  do
    {
a:
      bytes[n] = o & 0x7f;
      o >>= 7;
      if (o)
        {
	  bytes[n] |= 0x80;
	  if (flag)
	    goto a;
	}
      n++;
    }
  while (o);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  add_unwind_adjustsp(atoi(argv[1]));
  if (bytes[0] != 0x88 || bytes[1] != 0x07)
    abort ();
  return 0;
}
