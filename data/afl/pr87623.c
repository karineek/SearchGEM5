// Modification timestamp: 2023-08-14 16:03:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr87623.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct be {
    unsigned short pad[1];
    unsigned char  a;
    unsigned char  b;
} __attribute__((scalar_storage_order("big-endian")));

typedef struct be t_be;

struct le {
    unsigned short pad[3];
    unsigned char  a;
    unsigned char  b;
};

typedef struct le t_le;

bool a_or_b_different(t_be *x, t_le *y)
{
   return (x->a != y->a) || (x->b != y->b);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  t_be x = { .a = atoi(argv[1]), .b = atoi(argv[2]) };
  t_le y = { .a = atoi(argv[3]), .b = atoi(argv[4]) };

  if (a_or_b_different(&x, &y))
      __builtin_abort();

  return 0;
}

Note: The original code doesn't have any need for command-line arguments, so the modifications made are just to provide a sample usage for the arguments.