// Modification timestamp: 2023-08-14 12:58:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040823-1.c

#include <stdlib.h>
#include <string.h>

int *pwarn;

void bla (int pwarn_value) __attribute__ ((noreturn));

void bla (int pwarn_value)
{
  if (!pwarn_value)
    abort ();

  exit (0);
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int warn;
  memset (&warn, 0, sizeof (warn));
  pwarn = &warn;
  warn = atoi(argv[1]);

  bla(warn);
}
