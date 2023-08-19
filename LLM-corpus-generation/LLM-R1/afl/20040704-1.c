// Modification timestamp: 2023-08-14 12:56:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040704-1.c

#include <stdio.h>
#include <stdlib.h>

int main() {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = 0;
  
  for (; x - y ;)
    {
      abort ();
    label:
      return 0;
    }
    
  goto label;
}
