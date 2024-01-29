// Modification timestamp: 2023-08-14 13:31:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921110-1.c
extern void abort(void);
typedef void (*frob)();
frob f[] = {abort};

int main(void)
{
  exit(0);
}
