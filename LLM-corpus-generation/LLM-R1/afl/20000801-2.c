
// Modification timestamp: 2023-08-10 16:42:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/BitBench/bitcount/bitcount.c

extern void abort(void);
extern void exit(int);
int bar(void);
int baz(void);

struct foo {
  struct foo *next;
};

struct foo *test(struct foo *node)
{
  while (node) {
    if (bar() && !baz())
      break;
    node = node->next;
  }
  return node;
}

int bar(void)
{
  return 0;
}

int baz(void)
{
  return 0;
}

int main(int argc, char *argv[])
{
  struct foo a, b, *c;

  a.next = &b;
  b.next = (struct foo *)0;
  c = test(&a);
  if (c)
    abort();
  exit(0);
}
