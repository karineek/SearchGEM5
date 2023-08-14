// Modification timestamp: 2023-08-14 14:56:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr34415.c

#include <stdio.h>
#include <stdlib.h>

const char *__attribute__((noinline))
foo (const char *p)
{
  const char *end;
  int len = 1;
  for (;;)
    {
      int c = *p;
      c = (c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c);
      if (c == argv[1][0])
        end = p;
      else if (c == argv[2][0])
        {
          end = p;
          do
            p++;
          while (*p == '+');
        }
      else
        break;
      p++;
      len++;
    }
  if (len > 2 && *p == ':')
    p = end;
  return p;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <input>\n", argv[0]);
    return 1;
  }

  const char *input = argv[1];
  return foo (input) != input + 2;
}
