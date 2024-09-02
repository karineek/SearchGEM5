// Modification timestamp: 2023-08-14 13:41:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950426-2.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  long int i = atoi(argv[1]); // Replace constant with argument
  char ca = atoi(argv[2]); // Replace constant with argument

  if (i >> ca != -1073741824L)
    abort();

  if (i >> i / -2000000000L != -1073741824L)
    abort();

  exit(0);
}

Note that the code assumes two command-line arguments are provided: `argv[1]` for `i` and `argv[2]` for `ca`.