// Modification timestamp: 2023-08-14 15:56:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr81503.c
unsigned short a = 41461;
unsigned short b = 3419;
#if __SIZEOF_INT__ >= 4
int c = 0;

void foo() {
  if (a + b * ~(0 != 5))
    c = -~(b * ~(0 != 5)) + 2147483647;
}
#else
__INT32_TYPE__ c = 0;

void foo() {
  if (a + b * ~((__INT32_TYPE__)(0 != 5)))
    c = -~(b * ~((__INT32_TYPE__)(0 != 5))) + 2147483647;
}
#endif

int main() {
  foo();
  if (c != 2147476810)
    return -1;
  return 0;
}
