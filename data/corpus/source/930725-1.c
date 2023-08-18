// Modification timestamp: 2023-08-14 13:35:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930725-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int v;

char *
g ()
{
  return "";
}

char *
f ()
{
  return (v == 0 ? g () : 0);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  v = atoi(argv[1]);
  if (!strcmp (f (), argv[2]))
    exit (0);
  abort();
}
