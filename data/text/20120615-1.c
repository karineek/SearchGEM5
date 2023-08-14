// Modification timestamp: 2023-08-14 13:20:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20120615-1.c
extern void abort (void);

void __attribute__((noinline,noclone))
     test1(int i)
{
  if (i == 12)
    return;
  if (i != 17)
    {
      if (i == 15)
	return;
      abort ();
    }
}

int main() { test1 (15); return 0; }
