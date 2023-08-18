// Modification timestamp: 2023-08-14 14:41:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-6.c

#include <stdio.h>
#include <stdlib.h>

typedef __SIZE_TYPE__ size_t;
extern void abort(void);
extern void exit(int);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));

int compare(const void *a, const void *b, void *nonlocal)
{
  goto *(void *)nonlocal;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char array[3];
  void *nonlocal_label = &&nonlocal;
  qsort(array, 3, 1, compare);
  abort();

nonlocal:
  exit(0);
}


//Note: The label `nonlocal` is replaced with a function parameter `void *nonlocal` and the `goto nonlocal;` statement is replaced with `goto *(void *)nonlocal;`. This ensures that the GP (Global Pointer) is properly restored.