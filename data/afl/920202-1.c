// Modification timestamp: 2023-08-14 13:25:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920202-1.c

#include <stdio.h>
#include <stdlib.h>

static int rule_text_needs_stack_pop = 0;
static int input_stack_pos = 1;

int f(int input_stack_pos) {
  rule_text_needs_stack_pop = 1;

  if (input_stack_pos <= 0)
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <input_stack_pos>\n", argv[0]);
    return 1;
  }

  int input_stack_pos = atoi(argv[1]);
  f(input_stack_pos);
  exit(0);
}
