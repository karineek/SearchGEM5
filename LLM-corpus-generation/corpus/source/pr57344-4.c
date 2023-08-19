// Modification timestamp: 2023-08-14 15:28:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57344-4.c

#include <stdio.h>
#include <stdlib.h>

struct S
{
  long long int a : 59;
  long long int b : 54;
  char c;
  long long int : 0;
} s[2];
int i;

__attribute__((noinline, noclone)) void
foo (long long int x)
{
  if (x != -1220975898975746LL)
    __builtin_abort ();
  asm volatile ("" : : : "memory");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S t = { 0, atoi(argv[1]) };
  s[1] = t;
  for (; i < 1; i++)
    foo (s[1].b);
  return 0;
}
