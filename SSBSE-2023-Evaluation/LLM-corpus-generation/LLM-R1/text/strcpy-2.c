// Modification timestamp: 2023-08-14 16:14:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strcpy-2.c
/* Test to make sure strcpy works correctly. */
#define STRING "Hi!THE"

const char a[] = STRING;

void f(char *a) __attribute__((noinline));
void f(char *a)
{
  __builtin_strcpy (a, STRING);
}


int main(void)
{
  int i;
  char b[sizeof(a)] = {};
  f(b);
  for(i = 0; i < sizeof(b); i++)
    {
      if (a[i] != b[i])
	__builtin_abort ();
    }
  return 0;
}
