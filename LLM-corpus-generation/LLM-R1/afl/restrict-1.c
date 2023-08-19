// Modification timestamp: 2023-08-14 16:07:08
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/restrict-1.c

extern void abort ();

typedef struct
{
  int i, dummy;
} A;

A foo (const A* p, const A* q)
{
  A result;
  result.i = p->i+q->i;
  return result;
}

void bar (A* __restrict__ p)
{
  *p=foo(p,p);
  if (p->i!=2)
    abort();
}

int main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  A a;
  a.i = atoi(argv[1]);
  bar(&a);
  return 0;
}
