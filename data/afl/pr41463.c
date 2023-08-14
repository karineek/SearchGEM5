// Modification timestamp: 2023-08-14 15:07:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41463.c

#include <stdio.h>
#include <stdlib.h>

union tree_node;

struct tree_common
{
  int a;
  long b;
  long c;
  void *p;
  int d;
};

struct other_tree
{
  struct tree_common common;
  int arr[14];
};

struct tree_vec
{
  struct tree_common common;
  int length;
  union tree_node *a[1];
};

union tree_node
{
  struct other_tree othr;
  struct tree_vec vec;
};

union tree_node global;

union tree_node * __attribute__((noinline))
foo (union tree_node *p, int i)
{
  union tree_node **q;
  p->vec.a[i] = (union tree_node *) 0;
  q = &p->vec.a[1];
  *q = &global;
  return p->vec.a[i];
}

extern void abort (void);
extern void *malloc (__SIZE_TYPE__);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  union tree_node *p = malloc (sizeof (union tree_node));
  if (foo (p, atoi(argv[1])) != &global)
    abort ();
  return 0;
}
