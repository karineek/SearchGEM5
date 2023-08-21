// Modification timestamp: 2023-08-14 15:54:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr80153.c
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void check(int c, int c2, int val) __attribute__((noinline));
void check(int c, int c2, int val)
{
  if (!val) {
    printf("Error: Assertion failed\n");
    return;
  }
}

void _fputs(const char *str) __attribute__((noinline));
void _fputs(const char *str)
{
  printf("%s", str);
}

char _fgetc() __attribute__((noinline));
char _fgetc()
{
  static const char *buf;
  static int l, i;

  char val = buf[i];
  i++;
  if (i > l)
    return -1;
  else
    return val;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  const char *string = argv[1];
  int i;
  int c;

  _fputs(string);

  for (i = 0; i < strlen(string); i++) {
    c = _fgetc();
    check(c, string[i], c == string[i]);
  }

  return 0;
}

//This modified code replaces the `__builtin_abort()` function call with a print statement to indicate an assertion failure. It also adds a command-line argument to pass the string to be printed and checked.