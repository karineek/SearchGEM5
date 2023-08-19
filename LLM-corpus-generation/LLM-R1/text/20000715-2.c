
// Modification timestamp: 2023-08-10 16:39:16
// Original Source: https://github.com/llvm/llvm-test-suite

extern void abort(void);
extern void exit(int);

unsigned int foo(unsigned int a)
{
  return ((unsigned char)(a + 1)) * 4;
}

int main(void)
{
  if (foo((unsigned char)~0))
    abort ();
  exit(0);
}
