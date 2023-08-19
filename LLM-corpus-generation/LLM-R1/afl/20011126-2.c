// Modification timestamp: 2023-08-14 12:07:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011126-2.c

#include <stdio.h>

static const char *
test (const char *in, char *out)
{
  while (1)
    {
      if (*in == 'a')
	{
	  const char *p = in + 1;
      const char *argv2 = p;
	  while (*p == 'x')
	    ++p;
	  if (*p == 'b')
	    return p;
	  while (in < p)
	    *out++ = *in++;

      printf("in: %c\n", *in);
      printf("p: %c\n", *p);
	}
    }
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char out[4];
  test (argv[1], out);
  return 0;
}
