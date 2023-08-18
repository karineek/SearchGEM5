// Modification timestamp: 2023-08-14 13:27:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920520-1.c

#include <stdio.h>
#include <stdlib.h>

void foo(int *bar)
{
  *bar = atoi(argv[1]);
}

int bugger()
{
  int oldDepth, newDepth;

  foo(&oldDepth);

  switch (oldDepth)
  {
    case atoi(argv[2]):
    case atoi(argv[3]):
      newDepth = atoi(argv[2]);
      break;

    case atoi(argv[4]):
      newDepth = atoi(argv[3]);
      break;

    default:
      newDepth = atoi(argv[5]);
      break;
    }

  return newDepth - oldDepth;
}

int main(int argc, char *argv[]) {
  if (argc != 6) {
    printf("Usage: %s <value> <value> <value> <value> <value>\n", argv[0]);
    return 1;
  }

  if (bugger() != 0)
    abort ();
  exit (0);
}

//Note: In the `main` function, the number of arguments expected is 6, and the values are passed as command line arguments.