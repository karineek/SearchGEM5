// Modification timestamp: 2023-08-14 13:59:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/align-1.c
typedef int new_int __attribute__ ((aligned(16)));
struct S { int x; };

int main()
{
  if (sizeof(struct S) != sizeof(int))
    abort ();
  return 0;
}
