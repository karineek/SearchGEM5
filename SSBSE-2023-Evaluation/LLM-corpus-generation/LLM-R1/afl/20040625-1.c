// Modification timestamp: 2023-08-14 12:54:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040625-1.c

#include <stdio.h>
#include <stdlib.h>

struct __attribute__ ((packed)) s { struct s *next; };

struct s * __attribute__ ((noinline))
maybe_next (struct s *s, int t)
{
  if (t)
    s = s->next;
  return s;
}

int main(int argc, char *argv[]) {
  struct s s1, s2;

  if (argc != 3) {
    printf("Usage: %s <t> <next>\n", argv[0]);
    return 1;
  }

  int t = atoi(argv[1]);
  struct s *next = (struct s *) strtol(argv[2], NULL, 16);

  s1.next = next;
  if (maybe_next(&s1, t) != next)
    abort();
  exit(0);
}
