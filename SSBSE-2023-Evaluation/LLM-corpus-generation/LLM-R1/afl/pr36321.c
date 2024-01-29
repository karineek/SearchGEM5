// Modification timestamp: 2023-08-14 14:59:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr36321.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(char *str)
{
  int len2 = strlen (str);
  char *a = (char *) __builtin_alloca (0);
  char *b = (char *) __builtin_alloca (len2*3);

  if ((int) (a-b) < (len2*3))
    {
#ifdef _WIN32
      abort ();
#endif
      return;
    }
}

static char * volatile argp = "pr36321.x";

int main(int argc, char **argv)
{
  if (argc != 2) {
    printf("Usage: %s <str>\n", argv[0]);
    return 1;
  }

  foo (argv[1]);
  return 0;
}
