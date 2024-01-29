// Modification timestamp: 2023-08-14 13:20:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120207-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *strcpy (char *, const char *);
extern void abort (void);

char __attribute__((noinline))
test (int a, char *argv[])
{
  char buf[16];
  char *output = buf;

  strcpy (&buf[0], argv[1]);

  output += a;
  output -= 1;

  return output[0];
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (test(2, argv) != '1')
    abort ();

  return 0;
}
