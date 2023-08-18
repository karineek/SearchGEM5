// Modification timestamp: 2023-08-14 15:45:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr67226.c

#include <stdio.h>
#include <stdlib.h>

struct assembly_operand
{
  int type, value, symtype, symflags, marker;
};

struct assembly_operand to_input, from_input;

void __attribute__ ((__noinline__, __noclone__))
assemblez_1 (int internal_number, struct assembly_operand o1)
{
  if (o1.type != from_input.type)
    __builtin_abort ();
}

void __attribute__ ((__noinline__, __noclone__))
t0 (struct assembly_operand to, struct assembly_operand from)
{
  if (to.value == 0)
    assemblez_1 (32, from);
  else
    __builtin_abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 4) {
    printf("Usage: %s <to_input.value> <to_input.type> <from_input.value>\n", argv[0]);
    return 1;
  }

  to_input.value = atoi(argv[1]);
  to_input.type = atoi(argv[2]);
  to_input.symtype = 2;
  to_input.symflags = 3;
  to_input.marker = 4;

  from_input.value = atoi(argv[3]);
  from_input.type = 6;
  from_input.symtype = 7;
  from_input.symflags = 8;
  from_input.marker = 9;

  t0(to_input, from_input);

  return 0;
}

