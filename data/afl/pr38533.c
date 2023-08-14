// Modification timestamp: 2023-08-14 15:03:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38533.c

int foo(int e, int f) {
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  asm volatile ("" : "=r" (f) : "0" (0));
  e |= f;
  return e;
}

int main() {
  int e = 0;
  int f;
  e = foo(e, f);
  if (e)
    __builtin_abort();
  return 0;
}
