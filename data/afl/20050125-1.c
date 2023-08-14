// Modification timestamp: 2023-08-14 13:02:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050125-1.c

#include <stdlib.h>
#include <stdio.h>

struct parse {
  char *next;
  char *end;
  int error;
};

int seterr(struct parse *p, int err)
{
  p->error = err;
  return 0;
}

void bracket_empty(struct parse *p)
{
  if (((p->next < p->end) && (*p->next++) == ']')  ||  seterr(p, 7)) { }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct parse p;
  p.next = p.end = argv[1];

  p.error = 0;
  bracket_empty(&p);
  if (p.error != 7)
    abort ();

  return 0;
}
