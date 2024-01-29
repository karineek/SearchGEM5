// Modification timestamp: 2023-08-14 14:29:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/ipa-sra-1.c

#include <stdio.h>
#include <stdlib.h>

struct bovid
{
  float red;
  int green;
  void *blue;
};

static int
__attribute__((noinline))
ox (int fail, struct bovid *cow)
{
  int r;
  if (fail)
    r = cow->red;
  else
    r = 0;
  return r;
}

int main (int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value> <pointer>\n", argv[0]);
    return 1;
  }

  int r;

  r = ox ((atoi(argv[1]) > 2000), (void *)atoi(argv[2]));
  return r;
}

