// Modification timestamp: 2023-08-14 14:53:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr31072.c
extern volatile int ReadyFlag_NotProperlyInitialized;

volatile int ReadyFlag_NotProperlyInitialized=1;

int main(void)
{
  if (ReadyFlag_NotProperlyInitialized != 1)
    __builtin_abort ();
  return 0;
}
