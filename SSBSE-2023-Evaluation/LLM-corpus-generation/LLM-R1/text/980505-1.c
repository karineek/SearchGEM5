// Modification timestamp: 2023-08-14 13:48:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980505-1.c
static int f(int) __attribute__((const));
int main()
{
   int f1, f2, x;
   x = 1; f1 = f(x);
   x = 2; f2 = f(x);
   if (f1 != 1 || f2 != 2)
     abort ();
   exit (0);
}
static int f(int x) { return x; }
