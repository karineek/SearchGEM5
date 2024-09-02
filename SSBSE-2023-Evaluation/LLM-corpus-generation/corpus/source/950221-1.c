// Modification timestamp: 2023-08-14 13:41:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950221-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parsefile
{
  long fd;
  char *buf;
};
struct parsefile basepf;
struct parsefile *parsefile = &basepf;
#ifdef STACK_SIZE
int filler[STACK_SIZE / (2 * sizeof(int))];
#else
int filler[0x3000];
#endif
int el;

char *
g1(int a, int *b)
{
}

g2(long a)
{
  if (a != 0xdeadbeefL)
    abort();
  exit(0);
}

void f()
{
  register char *p, *q;
  register int i;
  register int something;

  if (parsefile->fd == 0L && el)
  {
    const char *rl_cp;
    int len;
    rl_cp = g1(el, &len);
    strcpy(p, rl_cp);
  }
  else
  {
  alabel:
    i = g2(parsefile->fd);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  el = atoi(argv[1]);
  parsefile->fd = 0xdeadbeefL;
  f();
  return 0;
}
