// Modification timestamp: 2023-08-04 13:47:54
// Original Source: https://github.com/c-testsuite/c-testsuite/blob/master/tests/single-exec/00051.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x = 0;

  switch (x)
    case 0:
      ;
  switch (x)
    case 0:
      switch (x) {
        case 0:
          goto next;
        default:
          return 1;
      }
  return 1;
next:
  switch (x)
    case 1:
      return 1;
  switch (x) {
    {
      x = atoi(argv[1]);
      foo:
      case 1:
        return 1;
    }
  }
  switch (x) {
    case 0:
      return x;
    case 1:
      return 1;
    default:
      return 1;
  }
}
