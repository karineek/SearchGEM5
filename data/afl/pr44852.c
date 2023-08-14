// Modification timestamp: 2023-08-14 15:13:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44852.c

#include <stdio.h>
#include <string.h>

__attribute__ ((__noinline__))
char *sf(char *s, char *s0)
{
  asm ("");
  while (*--s == '9')
    if (s == s0)
      {
        *s = '0';
        break;
      }
  ++*s++;
  return s;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char s[] = "999999";
  char *x = sf (s + atoi(argv[1]), s);
  if (x != s + 1 || strcmp(s, "199999") != 0)
    abort();
  return 0;
}
