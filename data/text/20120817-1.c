// Modification timestamp: 2023-08-14 13:20:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120817-1.c
typedef unsigned long long u64;
unsigned long foo = 0;
u64 f() __attribute__((noinline));

u64 f() {
  return ((u64)40) + ((u64) 24) * (int)(foo - 1);
}

int main ()
{
  if (f () != 16)
    abort ();
  exit (0);
}
