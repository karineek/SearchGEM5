// Modification timestamp: 2023-08-14 16:02:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr86492.c

#include <stdio.h>
#include <stdlib.h>

union U
{
  unsigned int r;
  struct S
  {
    unsigned int a:12;
    unsigned int b:4;
    unsigned int c:16;
  } f;
};

__attribute__((noipa)) unsigned int
foo (unsigned int x)
{
  union U u;
  u.r = 0;
  u.f.c = x;
  u.f.b = 0xe;
  return u.r;
}

int
main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  union U u;
  if (__CHAR_BIT__ * __SIZEOF_INT__ != 32 || sizeof (u.r) != sizeof (u.f))
    return 0;
  u.r = foo(atoi(argv[1]));
  if (u.f.a != 0 || u.f.b != 0xe || u.f.c != atoi(argv[1]))
    __builtin_abort ();
  return 0;
}

Note: I've added code to handle command-line arguments.