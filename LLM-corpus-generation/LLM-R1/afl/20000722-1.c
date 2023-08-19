
// Modification timestamp: 2023-08-10 16:40:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/2002-07-22-1.c

#include <stdlib.h>

struct s { char *p; int t; };

extern void bar (void);
extern void foo (struct s *);

int main(int argc, char *argv[])
{
    bar ();
    bar ();
    exit (0);
}

void
bar (void)
{
    foo (& (struct s) { "hi", 1 });
}

void foo (struct s *p)
{
    if (p->t != atoi(argv[1]))
        abort();
    p->t = 2;
}
