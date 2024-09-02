// Modification timestamp: 2023-08-14 12:35:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020619-1.c

#include <stdio.h>
#include <stdlib.h>

#if (__SIZEOF_INT__ == 4)
typedef int int32;
#elif (__SIZEOF_LONG__ == 4)
typedef long int32;
#else
#error Add target support for int32
#endif

static int32 ref(int32 arg0, int32 arg1, int32 arg2, int32 arg3)
{
  union {
    char c[5];
    int32 i;
  } u;

  __builtin_memset (&u, 0, sizeof(u));
  u.c[0] = arg0;
  u.c[1] = arg1;
  u.c[2] = arg2;
  u.c[3] = arg3;

  return u.i;
}

int main(int argc, char *argv[])
{
  if (argc != 5) {
    printf("Usage: %s <arg0> <arg1> <arg2> <arg3>\n", argv[0]);
    return 1;
  }

  int32 b = ref(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
  if (b != 0x01020304 && b != 0x04030201)
    abort ();

  return 0;
}
