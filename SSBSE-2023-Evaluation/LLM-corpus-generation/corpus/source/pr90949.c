// Modification timestamp: 2023-08-14 16:05:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr90949.c
#include <stdlib.h>

#include <stdio.h>

void my_puts(const char *str) { }

void my_free(void *p) { }

struct Node
{
  struct Node *child;
};

struct Node space[2] = { };

struct Node *my_malloc(int bytes)
{
  return &space[0];
}

void walk(struct Node *module, int cleanup)
{
  if (module == 0)
  {
    return;
  }
  if (!cleanup)
  {
    printf("No cleanup\n");
  }
  walk(module->child, cleanup);
  if (cleanup)
  {
    my_free(module);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct Node *node = my_malloc(atoi(argv[1]));
  node->child = 0;
  walk(node, 1);
}
