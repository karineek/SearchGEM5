
// Modification timestamp: 2023-08-10 16:36:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/Misc/C/20000703-1.c
#include <stdio.h>
#include <stdlib.h>

void abort(void);
void exit(int);
struct baz
{
  char a[17];
  char b[3];
  unsigned int c;
  unsigned int d;
};

void foo(struct baz *p, unsigned int c, unsigned int d)
{
  __builtin_memcpy (p->b, "abc", 3);
  p->c = c;
  p->d = d;
}

void bar(struct baz *p, unsigned int c, unsigned int d)
{
  ({ void *s = (p);
     __builtin_memset (s, '\0', sizeof (struct baz));
     s; });
  __builtin_memcpy (p->a, "01234567890123456", 17);
  __builtin_memcpy (p->b, "abc", 3);
  p->c = c;
  p->d = d;
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <c_value> <d_value>\n", argv[0]);
    return 1;
  }

  struct baz p;
  foo(&p, atoi(argv[1]), atoi(argv[2]));
  if (p.c != atoi(argv[1]) || p.d != atoi(argv[2]))
    abort();
  bar(&p, atoi(argv[3]), atoi(argv[4]));
  if (p.c != atoi(argv[3]) || p.d != atoi(argv[4]))
    abort();
  exit(0);
}
