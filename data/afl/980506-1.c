// Modification timestamp: 2023-08-14 13:49:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980506-1.c

#include <stdio.h>
#include <stdlib.h>

struct decision
{
  char enforce_mode;
  struct decision *next;
};

static void clear_modes(struct decision *p)
{
  goto blah;

foo:
  p->enforce_mode = 0;
blah:
  if (p)
    goto foo;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct decision *p = NULL;
  clear_modes(p);
  exit(0);
}
